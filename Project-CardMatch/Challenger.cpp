#include "Common.h"
#include "Challenger.h"

/*�ؽ����̺����*/
HashTable* Challenger::CreateHash(int size)
{
	HashTable* Hash = (HashTable*)malloc(sizeof(HashTable));
	Hash->table = (Np*)malloc(sizeof(Np)*size);
	Hash->tableSize = size;
	memset(Hash->table, NULL, sizeof(Np)*size);
	return Hash;
}

/*��常���*/
Np Challenger::CreateNode( int value,int x,int y)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->value = value;
	NewNode->x = x;
	NewNode->y = y;
	NewNode->next = NULL;
	return NewNode;
}

/*�����͸� �ؽ����̺� �ֱ�*/
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

/*�ؽ����̺��� ������ ������*/
void Challenger::Pop(HashTable *ht,Point p,int value)
{
	Np ttt;
	ttt=ht->table[value];
	
	if (ttt == NULL)
	{
		return;
	}
	else if (ttt->x == p.getX() && ttt->y == p.getY())//ttt�� ���� ��ġ�ϸ�
	{
		if (ttt->next)
			ht->table[value] = ttt->next;
		else
			ht->table[value] = NULL;
	}
	else
	{
		for (ttt; ttt->next != NULL; ttt = ttt->next)//ttt�� ������尡 ���������� �ݺ�
		{
			if (ttt->next->x == p.getX() && ttt->next->y == p.getY())//ttt�� ��������� ���� ��ġ�ϸ�
			{
				break;
			}
		}
		if (ttt->next)
		{
			if (ttt->next->next)
			{
				ttt->next = ttt->next->next;//�߰��ǳʶٱ�
			}
			else
				ttt->next = NULL;
		}
		else
			ttt->next = NULL;
	}
	HashArray[value]--;
}
/*ã�� ���� ������ Ʈ�� ������ �c��*/
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


/*�迭 �� �ؽ����̺� �ʱ�ȭ*/
Challenger::Challenger()
{
	ht = CreateHash(LAST_CARD_NUMBER + 1); 
	memset(HashArray, 0, sizeof(HashArray));
	memset(xyArray, 0, sizeof(xyArray));
	memset(CardArr, 0, sizeof(CardArr));
}

/*�������� Ʈ��*/
bool Challenger::checkboardRange(int x, int y)
{
	if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE)
		return false;
	else
		return true;
}

/*���� ���� �ֳ����� HashArray���� 2�̻��̸� ����ī�尡�ִ°�*/
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

/*ù��°�� �ֱ�*/
Point Challenger::inputFirst()
{

	if (SameValue())//�������������� �ؽ����̺��� ��带 �ϳ�������
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

/*�ι�°�� �ֱ�*/
Point Challenger::inputSecond()
{
	if (same)//�������־�
	{
		Point p(ht->table[same]->next->x, ht->table[same]->next->y);
		return p;		
	}
	else
	{
		if (ht->table[gru]&&HashArray[ht->table[gru]->value]>=2)//ù�����������̶� ���� value�����ִ°��
		{
			Point p(ht->table[gru]->x, ht->table[gru]->y);
			return p;
		}
		else//����
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

/*ī�尪üũ*/
void Challenger::checkCardInfo(Point point, int card)
{
	if (FindData(ht, point.getX(), point.getY(), card))//�̹�����
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

/*ī�尡 ��ġ�Ҷ�*/
void Challenger::matchedCard(Point p1, Point p2, int card)
{
	Pop(ht, p1, card);
	Pop(ht, p2, card);
	CardArr[card - 1]++;
}