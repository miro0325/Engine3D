#pragma once

class Vector
{
public:
	float x;
	float y;

public:
	Vector() { }
	Vector(float x, float y) : x(x), y(y) { }
	Vector(POINT pt) : x(static_cast<float>(pt.x)), y(static_cast<float>(pt.y)) { }


	// �ٸ� ���Ϳ��� ������ ���� ������ �����ε�
	Vector operator+(const Vector& other)
	{
		Vector ret;
		ret.x = x + other.x;
		ret.y = y + other.y;

		return ret;
	}

	void operator+=(const Vector& other)
	{
		x += other.x;
		y += other.y;
	}

	// �ٸ� ���Ϳ��� ������ ���� ������ �����ε�
	Vector operator-(const Vector& other)
	{
		Vector ret;
		ret.x = x - other.x;
		ret.y = y - other.y;

		return ret;
	}

	void operator-=(const Vector& other)
	{
		x -= other.x;
		y -= other.y;
	}

	// ��Į�� ���� ������ ���� ������ �����ε�
	Vector operator*(float value)
	{
		Vector ret;
		ret.x = x * value;
		ret.y = y * value;

		return ret;
	}

	void operator*=(float value)
	{
		x *= value;
		y *= value;
	}

	// ������ ũ��(Length)�� ���ϴ� �Լ��� ����

	// ��Ʈ ������ ���� ������ �����ϴ� �Լ�
	float LengthSquared()
	{
		return x * x + y * y;
	}

	// ���� ���� ������ �����Ǿ������Ƿ�, �װ��� �̿��� ��Ʈ�� ���� ��ȯ�ϴ� �Լ�
	float Length()
	{
		return (float)::sqrt(LengthSquared());
	}

	// ����ȭ (ũ�Ⱑ 1�� ���ͷ� ����� ��ȯ) �Լ��� ����
	// * (x, y)�� ���� �� (x / x�� ����, y / y�� ����)�� ���� ���͸� ���� �� �ִ�.
	void Normalize()
	{
		float length = Length();

		// ���̰� 0�� ��쿡�� ���⺤�͸� ���� �� ���� (����ó��)
		if (length < 0.00000000001f)
		{
			return;
		}

		x /= length;
		y /= length;
	}

	// ������ ����� ��ȯ�ϱ� ���� �Լ��� ����
	float Dot(Vector other)
	{
		// ���� ���� : x1*x2 + y1*y2
		return (x * other.x) + (y * other.y);
	}

	// ������ ����� ��ȯ�ϱ� ���� �Լ��� ����
	float Cross(Vector other)
	{
		// ���� ���� : x1*y2 - x2*y1
		return (x * other.y) - (other.x * y);
	}

};

// ���� ������ �����ϱ� ���� ����ü�� ���� (int)
class VectorInt
{
public:
	int32 x;
	int32 y;

public:
	VectorInt() { }
	VectorInt(int32 x, int32 y) : x(x), y(y) { }

	VectorInt(POINT pt) : x(static_cast<int32>(pt.x)), y(static_cast<int32>(pt.y)) { }

	// �ٸ� ���Ϳ��� ������ ���� ������ �����ε�
	VectorInt operator+(const VectorInt& other)
	{
		VectorInt ret;
		ret.x = x + other.x;
		ret.y = y + other.y;

		return ret;
	}

	void operator+=(const VectorInt& other)
	{
		x += other.x;
		y += other.y;
	}

	// �ٸ� ���Ϳ��� ������ ���� ������ �����ε�
	VectorInt operator-(const VectorInt& other)
	{
		VectorInt ret;
		ret.x = x - other.x;
		ret.y = y - other.y;

		return ret;
	}

	void operator-=(const VectorInt& other)
	{
		x -= other.x;
		y -= other.y;
	}

	// Ư�� ���� ������ ���� ������ �����ε�
	VectorInt operator*(float value)
	{
		VectorInt ret;
		ret.x = x * (int32)value;
		ret.y = y * (int32)value;

		return ret;
	}

	// ������ ����� ��ȯ�ϱ� ���� �Լ��� ����
	float Dot(VectorInt other)
	{
		// ���� ���� : x1*x2 + y1*y2
		return (float)(x * other.x) + (float)(y * other.y);
	}

	// ������ ����� ��ȯ�ϱ� ���� �Լ��� ����
	float Cross(VectorInt other)
	{
		// ���� ���� : x1*y2 - x2*y1
		return (float)(x * other.y) - (float)(other.x * y);
	}

};
