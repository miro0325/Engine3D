#pragma once

// ȭ���� �׸��� ���� �� ȭ�鿡 �ִ� ��� ó��(��ü�� ����ִ� ��) ������ �մϴ�.
class Scene
{
protected:
	float deltaTime;

public:
	Scene();
	virtual ~Scene();

	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Render(HDC hdc);

};