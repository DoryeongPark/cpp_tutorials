#pragma once
#include <iostream>	
#include <string>

//Ŭ���� Box ����
class Box {
private:
	int width;//����
	int height;//����
	char fill;//ä����
public:
	Box(int w, int h);//������
	void setFill(char f);//ä��� �Լ�
	void setSize(int w, int h);//���� ���� Setter
	void draw();//�׸�
};