#include <stdio.h>
#include <stdlib.h>

typedef struct node {//노드 구조체 생성
	int key;//키 생성
	struct node *left;//왼쪽이름을 가진 구조체 포인터
	struct node *right;//오른쪽 이름을 가진 구조체 포인터
} Node;//별명

int initializeBST(Node** h);//노드 초기화 함수

/* functions that you have to implement */
void inorderTraversal(Node* ptr);//inorder방식 순회 함수
void preorderTraversal(Node* ptr);//preorder 방식 순회 함수
void postorderTraversal(Node* ptr);// postorder 방식 순회 함수
int insert(Node* head, int key);//노드 입력 함수
int deleteLeafNode(Node* head, int key);//노드 삭제 함수
Node* searchRecursive(Node* ptr, int key);//Recursive 방식 노드 찾기 함수
Node* searchIterative(Node* head, int key);//Iterative 방식 노드 찾기 함수
int freeBST(Node* head);//메모리 초기화 함수

/* you may add your own defined functions if necessary */


int main()
{
	printf("[----- [Lee hyeondo]  [2019038085] -----]\n");//이름 학번 출력
	char command;//커멘드 변수
	int key;//입력받을 키 변수
	Node* head = NULL;//헤드라는 이름의 노드 초기화
	Node* ptr = NULL;// ptr이라는 노드 초기화	/* temp */

	do{//while의 조건에 따라 다시 반복
		printf("\n\n");//메뉴 출력
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #1                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = n      Delete Leaf Node             = d \n");
		printf(" Inorder Traversal    = i      Search Node Recursively      = s \n");
		printf(" Preorder Traversal   = p      Search Node Iteratively      = f\n");
		printf(" Postorder Traversal  = t      Quit                         = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);//커멘드 입력받음

		switch(command) {//커멘드에 따라 선택됨
		case 'z': case 'Z'://z이거나 Z이면 
			initializeBST(&head);//이진탐색트리 초기화
			break;
		case 'q': case 'Q'://q거나 Q이면 
			freeBST(head);//메모리 초기화
			break;
		case 'n': case 'N'://n이거나 N이면 
			printf("Your Key = ");
			scanf("%d", &key);//키를 입력받고
			insert(head, key);//키 입력
			break;
		case 'd': case 'D'://d거나 D이면 
			printf("Your Key = ");
			scanf("%d", &key);//키를 입력받고
			deleteLeafNode(head, key);//노드 삭제
			break;
		case 'f': case 'F'://f이거나 F이면 
			printf("Your Key = ");
			scanf("%d", &key);//키를 입력 받고
			ptr = searchIterative(head, key);//ptr에 Iteratively 방식으로 노드 검색하여 입력
			if(ptr != NULL)//검색한 노드를 찾았으면
				printf("\n node [%d] found at %p\n", ptr->key, ptr);// 노드의 키 값과 주소 출력
			else//못찻았으면 입력한 키를 못찾음을 출력
				printf("\n Cannot find the node [%d]\n", key);
			break;
		case 's': case 'S'://s이거나 S이면 
			printf("Your Key = ");
			scanf("%d", &key);//키를 입력받고
			ptr = searchRecursive(head->left, key);//ptr에 Recursive 방식으로 노드 검색하여 입력
			if(ptr != NULL)//찾았으면
				printf("\n node [%d] found at %p\n", ptr->key, ptr);//찾은 키 값과 주소 출력
			else//못찾았으면
				printf("\n Cannot find the node [%d]\n", key);//입력받은 키를 못찾음을 출력
			break;

		case 'i': case 'I'://i이거나 I이면 
			inorderTraversal(head->left);//inorder 방식으로 순회
			break;
		case 'p': case 'P'://p이거나 P이면 
			preorderTraversal(head->left);//preorder방식으로 순회
			break;
		case 't': case 'T'://t이거나 T이면 
			postorderTraversal(head->left);//postorder 방식으로 순회
			break;
		default://해당 되는 command가 없으면
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");//Concentration 출력
			break;
		}

	}while(command != 'q' && command != 'Q');//커멘드가 q 가 아닌동안 반복

	return 1;//종료
}

int initializeBST(Node** h) {//초기화 함수

	/* if the tree is not empty, then remove all allocated nodes from the tree*/
	if(*h != NULL)//만약 헤드노드가 비어있지않으면
		freeBST(*h);//헤드노드 초기화

	/* create a head node */
	*h = (Node*)malloc(sizeof(Node));//헤드노드 동적할당
	(*h)->left = NULL;//헤드노드의 왼쪽은 NULL	/* root */
	(*h)->right = *h;//헤드노드의 오른쪽은 헤드노드
	(*h)->key = -9999;//헤드노드의 키는 -9999
	return 1;//리턴 1
}



void inorderTraversal(Node* ptr)//inorder 방식 순회
{
	if(ptr) {//만약 ptr이 NULL이 아니면
		inorderTraversal(ptr->left);//ptr의 왼쪽으로 이동하여 함수 다시호출
		printf(" [%d] ", ptr->key);//키 출력
		inorderTraversal(ptr->right);//오른쪽으로 이동하여 함수 다시 호출
	}
}

void preorderTraversal(Node* ptr)//프리오더방식 순회
{
	if(ptr) {//ptr이 비어있지 않으면
		printf(" [%d] ", ptr->key);//키 출력
		preorderTraversal(ptr->left);//왼쪽으로 이동하여 함수 다시 호출
		preorderTraversal(ptr->right);//오른쪽으로 이동하여 함수 다시 호출
	}
}

void postorderTraversal(Node* ptr)//포스트오더 방식 순회
{
	if(ptr) {//ptr이 비어있지 않으면
		postorderTraversal(ptr->left);//왼쪽으로 이동하여 함수 다시호출
		postorderTraversal(ptr->right);//오른쪽으로 이동하여 함수 다시호출
		printf(" [%d] ", ptr->key);//키값 출력
	}
}


int insert(Node* head, int key)//입력 함수
{
	Node* newNode = (Node*)malloc(sizeof(Node));//newNode라는 노드 변수 생성하여 동적할당
	newNode->key = key;//키 입력
	newNode->left = NULL;//왼쪽 초기화
	newNode->right = NULL;//오른쪽 초기화

	if (head->left == NULL) {//만약 헤드노드의 왼쪽이 비어있으면
		head->left = newNode;//왼쪽에 입력받은 노드의 왼쪽 초기화
		return 1;//리턴
	}

	/* head->left is the root */
	Node* ptr = head->left;//ptr은 헤드의 왼쪽노드

	Node* parentNode = NULL;//부모노드는 0
	while(ptr != NULL) {//ptr이 0이될때까지 반복

		if(ptr->key == key) return 1;//만약 ptr의 키가 입력받은 키면

		parentNode = ptr;//부모노드에 ptr입력

		if(ptr->key < key)//만약 ptr의 키가 입력받은 키보다 작으면
			ptr = ptr->right;//ptr에 ptr의 오르쪽 노드 입력
		else//아니면
			ptr = ptr->left;//ptr에 ptr의 왼쪽 노드 입력
	}

	if(parentNode->key > key)//만약 부모노드의 키가 입력받은 키보다 크면
		parentNode->left = newNode;//부모노드의 왼쪽노드에 newNode 입력
	else//아니면
		parentNode->right = newNode;//부모노드의 오른쪽 노드에 newNode 입력
	return 1;//리턴
}

int deleteLeafNode(Node* head, int key)//노드 삭제 함수
{
	if (head == NULL) {//만약 헤드가 0이면
		printf("\n Nothing to delete!!\n");//삭제할게 없음을 출력
		return -1;//리턴 
	}

	if (head->left == NULL) {//헤드 노드의 왼쪽노드가 0이면
		printf("\n Nothing to delete!!\n");//삭제할게 없음을 출력
		return -1;//리턴 -1
	}

	Node* ptr = head->left;//노드 ptr에 헤드노드의 왼쪽 노드 입력


	/* we have to move onto children nodes,
	 * keep tracking the parent using parentNode */
	Node* parentNode = head;//부모노드에 헤드노드 입력

	while(ptr != NULL) {//ptr이 0인동안 반복

		if(ptr->key == key) {//ptr의 키가 입력받은 키이면
			if(ptr->left == NULL && ptr->right == NULL) {//ptr의 왼쪽은 0이고 오른쪽도 0이면

				/* root node case */
				if(parentNode == head)//부모노드가 헤드노드이면
					head->left = NULL;//헤드의 왼쪽노드는 0

				/* left node case or right case*/
				if(parentNode->left == ptr)//부모노드의 왼쪽노드가 ptr이면
					parentNode->left = NULL;//부모노드의 왼쪽 노드는 0
				else//아니면
					parentNode->right = NULL;//ptr의 오른쪽노드는 0

				free(ptr);//ptr의 메모리 초기화
			}
			else {//자식노드가 있으면
				printf("the node [%d] is not a leaf \n", ptr->key);//키는 not a leaf임을 출력
			}
			return 1;
		}

		/* keep the parent node */
		parentNode = ptr;//부모노드에 ptr입력

		/* key comparison, if current node's key is greater than input key
		 * then the new node has to be inserted into the right subtree;
		 * otherwise the left subtree.
		 */
		if(ptr->key < key)//ptr의 키가 입력받은 키보다 작으면
			ptr = ptr->right;//ptr은 오른쪽 노드로 이동
		else//아니면
			ptr = ptr->left;//ptr은 왼쪽으로 이동


	}

	printf("Cannot find the node for key [%d]\n ", key);//못찾았으면 키가 없음을 출력

	return 1;//리턴
}

Node* searchRecursive(Node* ptr, int key)//Recursive방식으로 노드 찾기함수
{
	if(ptr == NULL)//ptr이 0이면
		return NULL;//리턴

	if(ptr->key < key)//ptr의 키가 입력받은 키보다작으면
		ptr = searchRecursive(ptr->right, key);//ptr에 ptr의 오른쪽노드를 인자로하여 searchRecursive함수 호출
	else if(ptr->key > key)//ptr의 키가 입력받은 키보다 크면
		ptr = searchRecursive(ptr->left, key);//ptr의 왼쪽을 인자로 하여 함수 다시호출

	return ptr;//키값이 같으면 리턴 ptr

}
Node* searchIterative(Node* head, int key)//Iterative 방식 노드 찾기 함수
{
	/* root node */
	Node* ptr = head->left;//ptr에 헤드노드의 왼쪽 입력

	while(ptr != NULL)//ptr이 0이 아닌동안
	{
		if(ptr->key == key)//만약 ptr의 키가 입력받은 키이면
			return ptr;//리턴 ptr

		if(ptr->key < key) ptr = ptr->right;//ptr의 키가 작으면 ptr에 ptr의 오른쪽 노드 입력
		else//아니면
			ptr = ptr->left;//ptr의 왼쪽 노드 입력
	}

	return NULL;//리턴
}

void freeNode(Node* ptr)//노드 메모리 해제 함수
{
	if(ptr) {//만약 ptr의 값이 있으면
		freeNode(ptr->left);//ptr의 왼쪽 메모리 해제
		freeNode(ptr->right);//ptr의 오른쪽 매모리 해제
		free(ptr);//ptr 메모리 해제
	}
}

int freeBST(Node* head)//이진탐색트리 메모리 해제 함수
{

	if(head->left == head)//헤드의 왼쪽노드가 해드이면
	{
		free(head);//헤드노드 메모리 해제
		return 1;//리턴
	}

	Node* p = head->left;//헤드노드의 왼쪽노드는 p

	freeNode(p);//p의 메모리 해제

	free(head);//헤드노드 메모리 해제
	return 1;//리턴
}
