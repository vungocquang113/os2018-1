#include  <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>
	#include <string.h>
	#define  BUFFER_SIZE 10	
	

	typedef struct {
		char type; //0=fried chicken, 1=French fries
		int amount; //pieces or weight
		char unit; //0=piece, 1=gram
	}

	item;
	item buffer[BUFFER_SIZE];
	int first=0;
	int last=0;
	void produce(item *i) {
		while ((first + 1) % BUFFER_SIZE == last) {
		// do nothing -- no free buffer item
		}
		memcpy(&buffer[first], i, sizeof(item));
		first = (first + 1) % BUFFER_SIZE;
	}
	

	item* consume() {
		item *i = (item*)malloc(sizeof(item));
		while (first == last) {
		// do nothing -- nothing to consume
		}
		memcpy(i, &buffer[last], sizeof(item));
		last = (last + 1) % BUFFER_SIZE;
		return i;
	}
	

	int main (){
		item i1,i2;
		item *consumeitem=consume();
		i1.type='0';
		i1.amount=5;
		i1.unit='0';
		printf("First item: %c, %d, %c\n",i1.type,i1.amount,i1.unit);
		i2.type='1';
		i2.amount=100;
		i2.unit='1';
		printf("Second item: %c, %d, %c\n",i2.type,i2.amount,i2.unit);
		printf ("first=%d, last=%d\n",first,last);
		produce(&i1);
		printf("After produce item 1: %c,%d,%c\nfirst=%d\nlast=%d\n",i1.type,i1.amount,i1.unit,first,last);
		produce(&i2);
		printf("After produce item 2: %c,%d,%c\nfirst=%d\nlast=%d\n",i2.type,i2.amount,i2.unit,first,last);
		printf("After consuming item: %c, %d, %c\nfirst = %d\n last=%d\n\n", consumeitem->type, consumeitem->amount, consumeitem->unit, first, last);
		return 0;
	}
