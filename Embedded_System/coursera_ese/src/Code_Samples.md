# Code Samples   
- [Configuring Endianess](#Configuring-Endianess)
- [Configuring Peripherals](#Configuring-Peripherals)   
- [LIFO Buffer](#LIFO-Buffer)
- [Circular Buffer](#Circular-Buffer)
# Configuring Endianess

```
/*Switches endianness of variable pointed by ptr*/
void byte_swap32(uint32_t *ptr){
    uint8_t i, temp byte;
    for(i=0; i < 3; i++){
        temp_byte = *((uint8_t*)ptr +(3-i));
        *((uint8_t*)ptr +(3-i)) = *((uint8_t*)ptr +i);
        *((uint8_t*)ptr +i) = temp_byte;
    }
}

/*Assuming Little Endian*/
void main(){
    uint32_t var = 0xABCD1234;
    uint32_t *ptr = &var;
    byte_swap32(ptr);
    while(1);
}
```

# Configuring Peripherals   
```
// configure for 
// TASSEL = 2=0b10
// TAIE = 1 =0b1

volatile uint16_t * ta0_ctrl = (uint16_t*) 0x40000000; // create a pointer to this specific address which is Timer A0 control register
*ta0_ctrl = 0x202; // not sure how we got this

// if we write software that interacts with the peripheral address we make our code platform dependent and hard to read given address
```

# LIFO Buffer
```
typedef struct LIFO_Buf {
uint32_t length;
uint8_t * base;
uint8_t * head;
} LIFO_Buf_t;

LB_Status LIFO_Is_Buf_Full(LiIFO_Buf_t * lbuf) {
    /* Checks if buffer is initialized */
    if ( ! lbuf || ! lbuf->head || ! lbuf->base) {
        return LB_NULL;
    }
    /* Checks if in the range of buf[0] < index < buf[length] */
    if ( lbuf->head == lbuf->base + (lbuf->length - 1) ){
        return LB_FULL:
    }
    else {
        return LB_NOT_FULL;
    }
}

LB_Status LIFO_Add_Item(LiIFO_Buf_t * lbuf, uint8_t item) {
    /* Checks if buffer is initialized */
    if ( ! lbuf || ! lbuf->head || ! lbuf->base) {
        return LB_NULL;
    }
    /* Checks if buffer is full */
    if ( LIFO_Is_Buf_Full(lbuf) == LB_FULL ){
        return LB_FULL:
    }
    lbuf->head++;
    *lbuf->head = item;
    return LB_NO_ERROR;
}
```

# Circular Buffer
```
CB_Status CB_Add_Item(CB_Buf_t * cbuf, uint8_t item) {
/* Checks if buffer is initialized */
if ( ! cbuf || ! cbuf->head || ! cbuf->base) {
return CB_NULL;
}
/* Checks if the buffer is Full */
if ( CB_Is_Buf_Full(lbuf) == CB_FULL ){
return CB_FULL;
}
/* Checks if buffer is at the end of the allocated region, moves to beginning if so */
if ( cbuf->head == cbuf->head + (cbuf->length -1 ) ) {
cbuf->head = cbuf->base;
}
else {
cbuf->head++;
}
*cbuf->head = item;
return CB_NO_ERROR;
}
```