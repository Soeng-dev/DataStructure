#include "circularQueue.h"

void view(CircularQueue q)
{
	for (int i = q.front;
		i != q.rear;
		moveInCircular(&i, 1, q.maxElementCount))
	{
		printf("q[%d] : %d\n", i, q.elements[i]);

	}
}

int main()
{
	CircularQueue* q = createCircularQueue(8);
	for (int i = 0; i < 8; ++i)
	{
		if (!put(q, i))
			printf("%d failed\n", i);
		else
			printf("put %d\n", i);
	}
	printf("\n\nis full : %d\n\n", isCircularQueueFull(q));

	printf("\n\ncurrent : %d\n\n", getCQCurrentCount(q));


	for (int i = 0; i < 5; ++i)
	{
		printf("%d get %d\n", i, get(q));
	}

	printf("\n\nis full : %d\n\n", isCircularQueueFull(q));

	printf("\n\ncurrent : %d\n\n", getCQCurrentCount(q));



	for (int i = 0; i < 8; ++i)
	{
		if (!put(q, i))
			printf("%d failed\n", i);
		else
			printf("put %d\n", i);
	}
	printf("\n\nis full : %d\n\n", isCircularQueueFull(q));

	printf("\n\ncurrent : %d\n\n", getCQCurrentCount(q));

	for (int i = 0;i < q->maxElementCount;printf("i%d val %d\n", i, q->elements[i]), ++i);
	view(*q);

	deleteCircularQueue(q);
}