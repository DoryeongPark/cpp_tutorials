#include "Common.h"
#include "Challenger.h"

/*해시테이블생성*/
HashTable* Challenger::CreateHash(int size)
{
	HashTable* Hash = (HashTable*)malloc(sizeof(HashTable));
	Hash->table = (Np*)malloc(sizeof(Np)*size);
	Hash->tableSize = size;
	memset(Hash->table, NULL, sizeof(Np)*size);
	return Hash;
}

/*노드만들기*/
Np Challenger::CreateNode( int value,int x,int y)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->value = value;
	NewNode->x = x;
	NewNode->y = y;
	NewNode->next = NULL;
	return NewNode;
}

/*데이터를 해시테이블에 넣기*/
void Challenger::Data_set(HashTable* ht, int x,int y, int value)
{
	Node* NewNode = CreateNode(value, x, y);
	Np temp=ht->table[value];
	if (ht->table[value] == NULL) {
		ht->table[value] = NewNode;
	}
	else 
	{
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = NewNode;
	}
}

/*해시테이블에서 데이터 빼내기*/
void Challenger::Pop(HashTable *ht,Point p,int value)
{
	Np ttt;
	ttt=ht->table[value];
	
	if (ttt == NULL)
	{
		return;
	}
	else if (ttt->x == p.getX() && ttt->y == p.getY())//ttt의 값이 일치하면
	{
		if (ttt->next)
			ht->table[value] = ttt->next;
		else
			ht->table[value] = NULL;
	}
	else
	{
		for (ttt; ttt->next != NULL; ttt = ttt->next)//ttt의 다음노드가 없을때까지 반복
		{
			if (ttt->next->x == p.getX() && ttt->next->y == p.getY())//ttt의 다음노드의 값이 일치하면
			{
				break;
			}
		}
		if (ttt->next)
		{
			if (ttt->next->next)
			{
				ttt->next = ttt->next->next;//중간건너뛰기
			}
			else
				ttt->next = NULL;
		}
		else
			ttt->next = NULL;
	}
	HashArray[value]--;
}
/*찾는 값이 있으면 트루 없으면 폺스*/
bool Challenger::FindData(HashTable *ht, int x, int y, int value)
{
	Np List= ht->table[value];
	if (List == NULL)
		return NULL;
	while (List != NULL)
	{
		if (List->x == x&&List->y == y)
			return true;
		List = List->next;
	}
	return false;
}


/*배열 및 해시테이블 초기화*/
Challenger::Challenger()
{
	ht = CreateHash(LAST_CARD_NUMBER + 1); 
	memset(HashArray, 0, sizeof(HashArray));
	memset(xyArray, 0, sizeof(xyArray));
	memset(CardArr, 0, sizeof(CardArr));
}

/*범위내면 트루*/
bool Challenger::checkboardRange(int x, int y)
{
	if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE)
		return false;
	else
		return true;
}

/*같은 값이 있나없나 HashArray에서 2이상이면 같은카드가있는거*/
int Challenger::SameValue()
{
	same = 0;
	for (int i=1; i < LAST_CARD_NUMBER + 1; i++)
	{
		if (HashArray[i] >= 2)
		{
			same = i;
			return i;
		}
	}
	return 0;
}

/*첫번째값 넣기*/
Point Challenger::inputFirst()
{

	if (SameValue())//같은값이있을땐 해시테이블의 노드를 하나가져옴
	{
		Point p(ht->table[same]->x, ht->table[same]->y);
		return p;
	}
	else
	{
		while (true)
		{
			int small = CardArr[0];
			int smallnum=0;
			int m = 0;
			for (int i = 0; i < LAST_CARD_NUMBER; i++)
			{
				if (HashArray[i+1]>0&&CardArr[i] <= small)
				{
					m = 1;
					smallnum = i+1;
					small = CardArr[i];
				}
			}
			if (m == 1)
			{
				for (int k = ht->table[smallnum]->x - 3; k < ht->table[smallnum]->x + 3; k++)
				{
					for (int j = 0; j < BOARD_SIZE; j++)
					{
						if (checkboardRange(k, j) && xyArray[k][j] == 0)
						{
							Point p(k, j);

							return p;
						}
					}
				}
			}
			
				int t = rand() % BOARD_SIZE;
				int s = rand() % BOARD_SIZE;
				if (checkboardRange(t, s) && xyArray[t][s] == 0);
				{
					Point p(t, s);
					p1 = p;
					return p;
				}
			
		}
	}
}

/*두번째값 넣기*/
Point Challenger::inputSecond()
{
	if (same)//같은게있엉
	{
		Point p(ht->table[same]->next->x, ht->table[same]->next->y);
		return p;		
	}
	else
	{
		if (ht->table[gru]&&HashArray[ht->table[gru]->value]>=2)//첫번쨰랜덤값이랑 같은 value값이있는경우
		{
			Point p(ht->table[gru]->x, ht->table[gru]->y);
			return p;
		}
		else//없엉
		{
			while (true)
			{
					int t = rand() % BOARD_SIZE;
					int s = rand() % BOARD_SIZE;
					if (checkboardRange(t, s) && xyArray[t][s] == 0);
					{
						Point p(t, s);
						p1 = p;
						return p;
					}
			}
		}
	}
}

/*카드값체크*/
void Challenger::checkCardInfo(Point point, int card)
{
	if (FindData(ht, point.getX(), point.getY(), card))//이미존재
	{
	}
	else if(xyArray[point.getX()][point.getY()]==0)
	{
		 
		gru = card;
		HashArray[card] += 1;
		xyArray[point.getX()][point.getY()]=1;
		Data_set(ht, point.getX(), point.getY(), card);
	}
	
}

/*카드가 일치할때*/
void Challenger::matchedCard(Point p1, Point p2, int card)
{
	Pop(ht, p1, card);
	Pop(ht, p2, card);
	CardArr[card - 1]++;
}