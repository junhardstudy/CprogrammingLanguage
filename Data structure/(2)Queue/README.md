# 개요

1. 배열로 큐 구조를 만들었습니다.

2. 링크드 리스트로 큐 구조를 만들었습니다.

3. 큐에 필요한 여러 operation이 정의되어 있습니다.

4. 위에서 언급한 것들을 바탕으로, 은행 이용자들의 예약 대기열을 만들어봅니다.


***

## Queue

큐(Queue)의 경우, 스택과는 다르게 한쪽 방향으로만 데이터의 삽입이 이루어지고 다른 한쪽 방향으로만 오직 데이터의 추출이 이루어집니다.
<br>
따라서, 첫번째로 들어온 데이터가 첫번째로 읽을수 있으므로 First In, First Out구조를 지닙니다.
<br>
<br>
큐 구조에 대해서는 다음과 같은 기본 연산이 필요합니다.

1. Enqueue : 큐에 데이터를 삽입합니다

2. Dequeue : 큐에서 데이터를 가져옵니다.

3. QueueRetrieve : 큐에서 데이터를 읽어옵니다(only retrieve, not delete) 

## Array로 구현된 Queue

![사진](./image/array.png)

먼저 데이터가 삽입되는 쪽을 Rear, 데이터를 추출하는 쪽을 Front라고 한다면 배열에서는 논리적으로 index의 값을 통해 Front와 Rear를
지정할 수 있습니다.

본 프로그램에서는 배열 사이즈를 6으로 잡았습니다.

사이즈가 6인 배열에 대해 index를 이용한 큐구조는 아래와 같이 대응될 수 있습니다.

![사진](./image/arraytable.JPG)

즉 Enqueue, Dequeue를 할때마다 index들이 변경되어 논리적으로 Rear와 Front를 담당합니다.

큐가 가득찼는지, 비었는지를 확인하려면 아래 조건을 확인하면 됩니다.

Index condition

1. Front == Rear -> Empty Queue

2. Front == (Rear + 1)%Queue_size -> Full Queue

## Linked list로 구현된 Queue

![사진](./image/linkedlist.png)

Linked list로 구현하는 경우, Queue를 담당하는 데이터를 만든뒤 해당 Queue데이터에서 Front와 Rear를 주소값으로 확인합니다.

Queue데이터의 Front와 Rear만 명시해주면, 큐 내부에서는 링크드 리스트 구조형태 때문에 서로 link로 연결되어 있습니다.


***

## 소스코드

```c
typedef struct {
	char name[20];
}customer_info;

typedef struct {
	customer_info* customer[6];
	int front;
	int rear;
	int size;

}queue_array;
```
배열로 큐구조를 생성할 때, 필요한 구조체들입니다.

배열로 생성하기 때문에, 선언시에 큐의 구조가 이미 정해집니다.

Front와 Rear는 배열의 index를 통해 구분합니다.
<br>
<br>
<br>

```c
typedef struct customer_node{
	char name[20];
	struct customer_node* next;
}Node;

typedef struct {
	
	Node* front;
	Node* rear;
}queue_linked_list;
```
링크드 리스트로 큐구조를 생성할 때, 필요한 구조체들입니다.

링크드 리스트 형태이기 때문에, 큐의 각 데이터들은 노드로 생각할 수 있으며 링크드 리스트의 특성상 다음 노드에 대한 주소정보가 필요하므로 자기 참조
구조체를 통해 다음노드와 이어줍니다.

배열과 달리 동적할당을 하기때문에 큐 사이즈가 고정되지 않습니다.
<br>
<br>
<br>


## 결과