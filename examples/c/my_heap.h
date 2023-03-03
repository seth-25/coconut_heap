#ifndef COCONUT_MY_HEAP_H
#define COCONUT_MY_HEAP_H

#ifdef __cplusplus
extern "C" {
#endif
void* create_heap();
void heap_push(void* p, float *ts , float val);
void heap_delete(void *p);
float heap_top(void* p);
void heap_pop(void* p);
void delete_heap(void *p);
int heap_size(void* p);
#ifdef __cplusplus
};
#endif

#endif //COCONUT_MY_HEAP_H