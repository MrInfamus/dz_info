#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//char *sp = spec(#type); \
//log_info(concat("DECLARE_APPEND hasharr->index = %d, hasharr->count = %d, hasharr->array[%d] = (%s)(item) = ", sp), hasharr->index, hasharr->count, hasharr->index, #type, (type)item);
#if 0
	#define log_info(M, ...) printf("[INFO] (%s:%d) " M "\n",\
        __FILE__, __LINE__, ##__VA_ARGS__)
#else
	#define log_info(M, ...)
#endif


char* spec(const char a[])
{
	if(strcmp(a, "int") == 0)         return "%d";
	else if(strcmp(a, "char") == 0)   return "%c";
	else if(strcmp(a, "float") == 0)  return "%f";
	else if(strcmp(a, "double") == 0) return "%lf";
	else if(strcmp(a, "char*") == 0)  return "%s";
	else                              return "%d";
}

char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

#define DECLARE_HASHARR(type) \
	typedef struct Hasharr_##type Hasharr_##type; \
	struct Hasharr_##type { \
		unsigned int count; \
		unsigned int step; \
		unsigned int index; \
		type* array; \
	};

#define DECLARE_HASHARRINIT(type) \
	void hashArrInit_##type(Hasharr_##type *hasharr, int count, int step) \
	{ \
		log_info("DECLARE_HASHARRINIT FOR %s", #type); \
		hasharr->index = 0; \
		hasharr->count = (unsigned int)count; \
		hasharr->step = (unsigned int)step; \
		hasharr->array = (type*)malloc(count * sizeof(type)); \
	}

#define DECLARE_APPEND(type) \
	void append_##type(Hasharr_##type *hasharr, type item) \
	{ \
		log_info("DECLARE_APPEND (int)hasharr->count - 1 = %d", ((int)hasharr->count - 1)); \
		while((int)hasharr->count - 1 <= 0 ){ \
			hasharr->array = (type*)realloc(hasharr->array, (hasharr->index + hasharr->step) * sizeof(type)); \
			log_info("DECLARE_APPEND realloc Worked!"); \
			(hasharr->count) = hasharr -> step; \
		} \
		(hasharr->array)[hasharr->index] = (type)item; \
		(hasharr->index)++; \
		(hasharr->count)--; \
	}

#define DECLARE_PRINT(type) \
	void print_##type(const Hasharr_##type hasharr) \
	{ \
		char *sp = spec(#type); \
		int i; \
		printf("["); \
		for(i = 0; i < hasharr.index - 1; i++) \
		{ \
			printf(concat(sp, ", "), (type)hasharr.array[i]); \
		} \
		printf(concat(sp, "]\n"), (type)hasharr.array[i]); \
	}

#define DECLARE_EXTAND(type) \
	void extend_##type(Hasharr_##type *hasharr1, Hasharr_##type *hasharr2) \
	{ \
		hasharr1->array = (type*)realloc(hasharr1->array, (hasharr1->index + hasharr2->index) * sizeof(type)); \
		for(int i = hasharr1->index; i < hasharr1->index + hasharr2->index; i++) \
		{ \
			(hasharr1->array)[i] = (hasharr2->array)[i - hasharr1->index]; \
		} \
		(hasharr1->index)+= hasharr2->index; \
		(hasharr1->count) = 1; \
	}

#define DECLARE_REMOVE(type) \
	void remove_##type(Hasharr_##type *hasharr, int ind) \
	{ \
		for(int i = ind; i < hasharr->index; i++) \
		{ \
			(hasharr->array)[i] = (hasharr->array)[i+1]; \
		} \
		(hasharr->index)--; \
		(hasharr->count)++; \
	}

#define DECLARE_REMOVEINTERVAL(type) \
	void removeInterval_##type(Hasharr_##type *hasharr, int ind0, int ind1) \
	{ \
		for(int i = ind0; i < hasharr->index; i++) \
		{ \
			(hasharr->array)[i] = (hasharr->array)[ind1+i]; \
		} \
		hasharr->index -= ind1; \
		hasharr->count += ind1; \
	}

#define DECLARE_FIND(type) \
	int find_##type(const Hasharr_##type *hasharr, type item) \
	{ \
		for(int i = 0; i < hasharr->index; i++) \
		{ \
			if(hasharr->array[i]==item) return i; \
		} \
		return -1; \
	}

#define DECLARE_COUNT(type) \
	int count_##type(const Hasharr_##type *hasharr, type item) \
	{ \
		int counter = 0; \
		for(int i = 0; i < hasharr->index; i++) \
		{ \
			if(hasharr->array[i] == item) counter++; \
		} \
		return counter; \
	}

#define DECLARE_HASHARRINITBYARRAY(type) \
	void hashArrInitByArr_##type(Hasharr_##type *hasharr, const type *array, int length, int step) \
	{ \
		log_info("DECLARE_HASHARRINITBYARRAY INIT FOR %s", #type); \
		hasharr->index = length; \
		hasharr->count = 0; \
		hasharr->step = step; \
		hasharr->array = (type*)malloc(length * sizeof(type)); \
		memcpy(hasharr->array, array, length * sizeof(type)); \
	}

#define DECLARE_INSERT(type) \
	void insert_##type(Hasharr_##type *hasharr, int ind, type item) \
	{ \
		while(((int)hasharr->count - 1) <= 0) \
		{ \
			hasharr->array = (type*)realloc(hasharr->array, (hasharr->index + hasharr->step) * sizeof(type)); \
			(hasharr->count) = hasharr->step; \
		} \
		\
		type temp0, temp1; \
		\
		temp0 = hasharr->array[ind]; \
		for(int i = ind-1; i < hasharr->index; i++) \
		{ \
			temp1 = (hasharr->array)[i+2]; \
			(hasharr->array)[i+2] = (hasharr->array)[i+1]; \
			(hasharr->array)[i+2] = temp0; \
			temp0 = temp1; \
		} \
		\
		(hasharr->array)[ind] = item; \
		\
		hasharr->index++; \
		hasharr->count--; \
	}

#define DECLARE_STANDART(type) \
	int length_##type(const Hasharr_##type hasharr) {return hasharr.index;} \
	type get_##type(const Hasharr_##type hasharr, int ind) {return (hasharr.array)[ind];} \
	void set_##type(Hasharr_##type *hasharr, int ind, int item) {if(ind <= hasharr->index) hasharr->array[ind] = item; else printf("Error, you out the index!\n");} \
	void change_step_##type(Hasharr_##type *hasharr, int step) {(hasharr->step) = (unsigned int)step;}

#define DECLARE_PACKEGE(type) \
	DECLARE_HASHARR(type) \
	\
	DECLARE_HASHARRINIT(type) \
	DECLARE_HASHARRINITBYARRAY(type) \
	DECLARE_STANDART(type) \
	\
	DECLARE_APPEND(type) \
	DECLARE_EXTAND(type) \
	DECLARE_INSERT(type)\
	\
	DECLARE_REMOVE(type) \
	DECLARE_REMOVEINTERVAL(type) \
	\
	DECLARE_COUNT(type) \
	DECLARE_FIND(type) \
	\
	DECLARE_PRINT(type)
