/**
 * 실습6. 이름 검색이 빠른 전화번호부 프로그램
 */
/* 2016120586 김유진 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD	100
//#define MAXNUM	100		// maximum number of phonebook entries
//#define EOL		'.'		// define end of input

struct tnode {
	char *name;
	struct plist {
		int id;				// 전화부 id
		char *item;			// 전화부 item
		struct plist *next;
	} *pb;
	struct tnode *left;
	struct tnode *right;
};

/* 전화부 ID */
enum PID { MOBILE = 1, HOME, OFFICE, FAX, ETC, EMAIL, ADDR, MEMO };

char *sItem[] = {
	"휴대폰", "집전화", "사무실전화", "팩스", "기타", "이메일", "주소", "메모"
};

struct tnode *createNode();		// create node and initialize
struct plist *createList();		// create list and initialize
struct tnode *addTree(struct tnode *, struct tnode *);	// add a node into binary tree
void addList(struct plist **pstart, struct plist *pj);	// add a list in increasing order of id
void treeprint(struct tnode *);
int dispNode(struct tnode *p, int opt);
int getmnum();
char *strdupl(char *);
// Requirement #3 //맨 아래에 추가하였습니다.
struct tnode *search(struct tnode *root, char *key);

int main()
{
	struct tnode *root, *pn;
	struct plist *pi, **pstart;
	char word[MAXWORD];
	int m, n;

	root = NULL;

	do {
		printf("\n\t===전화번호부====\n\n"
			"\t1. 추가\n"
			"\t2. 전체보기\n"
			"\t3. 검색\n"
			"\t4. 종료\n");
		while ((m = getmnum()) < 0 || 3 < m);
		switch (m) {
		case 1:	// 추가
			pn = createNode();
			printf("\n이름을 입력하세요: ");
			scanf(" %[^\n]", word);			// get line (after skipping white space)
			pn->name = strdupl(word);		// alloc and copy name
			pn->pb = NULL;
			pstart = &pn->pb;				// list start
			do {
				printf("\n선택하세요\n(0:종료 1:휴대폰 2:집전화 3:사무실전화 "
					"4:팩스 5:기타 6:이메일 7:주소 8:메모): ");
				scanf(" %d", &n);
				if (n < 0 || 8 < n) continue;
				if (!n) break;
				pi = createList();
				pi->id = n;
				printf("\n%s 내용을 입력하세요: ", sItem[n - 1]);
				scanf(" %[^\n]", word);
				pi->item = strdupl(word);
				addList(pstart, pi);
			} while (n);
			root = addTree(root, pn);
			break;
		case 2:	// 전체보기
			treeprint(root);
			printf("\n");
			break;
		case 3: // 검색
			printf("\n찾을 이름을 입력하세요: ");
			scanf(" %[^\n]", word);
			search(root, word);
		default: break;
		}
	} while (m);

	return 0;
}

/* getmnum: get menu number */
int getmnum() {
	int m;
	printf("\n\t원하는 메뉴를 선택하세요: ");
	scanf(" %d", &m);
	return m;
}

/* addTree: add a node at or below p
			print error message if there is same name */
struct tnode *addTree(struct tnode *p, struct tnode *r) {
	// TODO #1
	int cond = 0;

	if(p == NULL){ /* if p is empty, copy the contents of r to p */
        p = (struct tnode *)malloc(sizeof(struct tnode));
		p->name = strdupl(r->name);
		p->pb = r->pb;
		p->left = p->right = NULL;
	}
	else if((cond = strcmp(r->name,p->name)) == 0 ){ /* Duplicate name error */
		printf("\n 추가할 수 없습니다. error : 같은 이름이 존재합니다.\n");
	}
	else if( cond < 0 ){ p->left = addTree(p->left,r); }
	else  { p->right = addTree(p->right,r); }
	return p;
}

/* addList: add a list at or next pi in increasing order of id */
void addList(struct plist **pstart, struct plist *pj) {
	// TODO #2
	int pjid = pj->id;
    struct plist *temp = (struct plist *)malloc(sizeof(struct plist));
    //(*pstart) = (struct plist *)malloc(sizeof(struct plist));
    // int psid = ((*pstart)->id) - 1;

	if(*pstart == NULL){ /* If pstart is empty, initialize pstart to pj */
		(*pstart) = pj;
	}
	else
	{
		while( ((*pstart)->id) > (pjid-1) ){ /* Find a index */
			*pstart = (*pstart)->next;
		}
		temp = (*pstart)->next; /* insert node */
        (*pstart)->next = pj;
        pj->next = temp;
	}
	//pstart-> = (*pstart).
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p) {
	if (p != NULL) {
		treeprint(p->left);
		dispNode(p, 0);
		treeprint(p->right);
	}
}

/* dispNode: display a node including list
			(opt=1) display with line number, return number of items */
int dispNode(struct tnode *p, int opt) {
	// TODO #3
	struct plist* li = (struct plist *)malloc(sizeof(struct plist));
	int cnt = 1;
	li = p->pb;

    if(opt){ //if opt=1, display line number
		printf("\n1. 이름: ");
		printf("%s\n",p->name);
        while( li != NULL){
			printf("%d. %s: %s\n",++cnt ,sItem[(li->id)-1], li->item);
			li = li->next;

        }
        printf("\n");
        return (cnt-1); //return num of items
    }
    else{
        printf("\n이름: ");
		printf("%s\n",p->name);
        while( li != NULL){
			printf("%s: %s\n",sItem[(li->id)-1], li->item);
			li = li->next;
			cnt++;
        }
        printf("\n");
        return (cnt-1); //return num of items
    }
}

/* createNode: make and initialize a tnode */
struct tnode *createNode() {
	struct tnode *p;
	p = (struct tnode *) malloc(sizeof(struct tnode));
	p->left = p->right = NULL;
	return p;
}

/* createList: make and initialize a list */
struct plist *createList() {
	struct plist *p;
	p = (struct plist *) malloc(sizeof(struct plist));
	p->next = NULL;
	return p;
}

/* strdupl: make a duplicate of a string */
char *strdupl(char *s) {
	char *p;
	p = (char *)malloc(strlen(s) + 1);		// +1 for '\0'
	if (p != NULL)
		strcpy(p, s);
	return p;
}

/* 이름을 key로 하는 검색함수를 추가*/
struct tnode *search(struct tnode *root, char *key) {

	int cmp = 0;
	
	struct tnode *temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp = root;

	if(temp == NULL){
		printf("\n전화부에 존재하지 않는 이름입니다!\n");
		return temp;
	}
	else{
		cmp = strcmp(temp->name, key); //NULL이 들어가면 error가 발생한다
	}
	// printf("why???\n");

	while( cmp != 0){
		if(temp == NULL){ //빈 노드이면 NULL을 반환
			printf("\n전화부에 존재하지 않는 이름입니다.\n");
			return NULL;
		}
		else if(cmp < 0){ // key가 더 클 때
			temp = temp->right;
		}
		else if(cmp > 0){ //key가 더 작을 때
			temp = temp->left;
		}

		if(temp == NULL){    
			printf("\n전화부에 존재하지 않는 이름입니다.\n");
			return NULL;    
		}
		else{   cmp = strcmp(temp->name, key);   }
	}
		dispNode(temp,0);
		return temp;
}