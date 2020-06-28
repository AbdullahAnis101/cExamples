// implements a linked list of free blocks of memory that can be partitioned and given out as needed. A header contains two fields one indicating the size of the chunk and the second pointing to the next free block of memory


typedef struct header{
unsigned int   size;
struct header  *next ;   // Structures are a data structure used to hold different types of data items
}
header_t;

// we will need a used list and free list because of keeping track of blocks of memory currently in use of the well as well as blocks that are not used. 
//
// Creating two functions called morecore and add_to_free_list. morecore is used for more memory and 


static header_t base;     //Zero sized block to get us started
static header_t *freep = &base; //Points to first free block of memory
static header_t *usedp;// Points to first used block of memory

/*
 *Scan the free list and look for a place to put the block. Basically, we're looking for any block that the to-be-freed block might have been partitioned from.
 *
 */

static void 
add_to_free_list(header_t *bp)
{
header_t *p;
for (p= freep; !(bp >p && bp < p->next); p = p-> next)
	if (p >= p -> next && (bp >p || bp < p-> next))
		break;

if (bp + bp->size == p->next){
	bp->size += p->next->size;
	bp->next = p->next->next;

}else
	bp->next = p->next;
	
if (p + p->size == bp) {
	p->size +=bp->size;
	p->next = bp->next;
}else
	p->next =bp;
     freep = p;
     
  }


#define MIN_ALLOC_SIZE 4096  /* We allocate blocks in page sized chunks */

/*
 *Request more memory from the kernal.
 */

static header_t*
morecore(size_t num_units)
{
	void *vp;
	header_t *up;
	
	if (num_units >MIN_ALLOC_SIZE)
		num_units = MIN_ALLOC_SIZE / sizeof(header_t);
	if ((vp == sbrk(num_units* sizeof(header_t))) == (void*)-1)
		return NULL:

	
	up = (header_t*)vp;
	up->size = num_units;
	add_to_free_list(up);
	return freep;

}

//find a chunk fromt he free list and put it in the used list.

void*
GC_malloc(size_t alloc_size)
	{size_t num_units;
	header_t *p, *prevp;
	num_units = (alloc_size + sizeof(header_t) -1 ) / sizeof(header_t) + 1;
	prevp = freep;

	for (p = prevp->next;; prevp = p, p = p->next){
	
	
	}
		
		
		
	}



