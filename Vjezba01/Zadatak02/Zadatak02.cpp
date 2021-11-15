#include <iostream>
#include <iomanip>
using namespace std;

struct Matrix {
	int rows;
	int cols;
	float** mat_elements;
	void matrix_input();
	void generate_random_matrix();
	void create();
	void matrix_print();
	void matrix_sum();
	void matrix_diff();
	void matrix_prod();
	void matrix_transpose();
	void matrix_delete();

};

void matrix_input(Matrix* m)
{
	for (int i = 0; i < m->rows; i++)
	{
		for (int j = 0; j < m->cols; j++)
		{
			cout << "Input matrix elements: " << endl;
			cin >> m->mat_elements[i][j];
		}
	}
}

void generate_random_matrix(Matrix)
{
	int a;
	int b;
	srand(time(NULL));
	cout << "Input interval [a,b]: " << endl;
	cin >> a >> b;
	for (int i = 0; i < m->rows; i++)
	{
		for (int j = 0; j < m->cols; j++)
		{
			m->mat_elements[i][j] = (float)(a + rand() % (b - a) + 1);

		}
	}
}

void create(Matrix* m, int x, int y)
{

	m->rows = x;
	m->cols = y;
	m->mat_elements = new float* [x];
	for (int i = 0; i < x; i++)
	{
		m->mat_elements[i] = new float[y];
	}

}

void matrix_print(Matrix* m)
{
	if (m->mat_elements == NULL) {
		cout << "oops" << endl;
	}
	else
	{
		for (int i = 0; i < m->rows; i++)
		{
			for (int j = 0; j < m->cols; j++)
			{
				cout << right << fixed << setprecision(4) << m->mat_elements[i][j] << " ";
			}
			cout << endl;
		}
	}
}

void matrix_sum(Matrix* m1, Matrix* m2, Matrix* m3)
{

	if ((m1->rows != m2->rows) || (m1->cols != m2->cols))
	{
		cout << "Incompatible matrices" << endl;
	}
	else
	{
		create(m3, m1->rows, m1->cols);

		for (int i = 0; i < m1->rows; i++)
		{
			for (int j = 0; j < m1->cols; j++)
			{
				m3->mat_elements[i][j] = m1->mat_elements[i][j] + m2->mat_elements[i][j];

			}
		}
	}
}

void matrix_diff(Matrix* m1, Matrix* m2, Matrix* m3)
{

	if ((m1->rows != m2->rows) || (m1->cols != m2->cols))
	{
		cout << "Incompatible matrices" << endl;
	}
	else
	{
		create(m3, m1->rows, m1->cols);

		for (int i = 0; i < m1->rows; i++)
		{
			for (int j = 0; j < m1->cols; j++)
			{
				m3->mat_elements[i][j] = m1->mat_elements[i][j] - m2->mat_elements[i][j];

			}
		}
	}
}

void matrix_prod(Matrix* m1, Matrix* m2, Matrix* m3)
{
	if (m1->cols != m2->rows)
	{
		cout << "Incompatible matrices" << endl;
	}
	else
	{
		create(m3, m1->rows, m2->cols);
		for (int i = 0; i < m3->rows; i++)
		{
			for (int j = 0; j < m3->cols; j++)
			{
				int sum = 0;
				for (int k = 0; k < m1->cols; k++)
				{
					sum += (m1->mat_elements[i][k] * m2->mat_elements[k][j]);
				}
				m3->mat_elements[i][j] = sum;
			}
		}

	}
}

void matrix_transpose(Matrix* m1, Matrix* m3)
{
	create(m3, m1->cols, m1->rows);
	for (int i = 0; i < m3->cols; i++)
	{
		for (int j = 0; j < m3->rows; j++)
		{
			m3->mat_elements[j][i] = m1->mat_elements[i][j];
		}
	}
}

void matrix_delete(Matrix* m)
{
	for (int i = 0; i < m->rows; i++)
	{
		delete[] m->mat_elements[i];
	}
	delete[] m->mat_elements;
}



int main()
{
	Matrix m1, m2, m3;

	create(&m1, 3, 3);
	//matrix_input(&m1);
	generate_random_matrix(&m1);
	cout << "Matrix 1:\n";
	matrix_print(&m1);
	cout << "\n";

	create(&m2, 3, 3);
	generate_random_matrix(&m2);
	cout << "Matrix 2:\n";
	matrix_print(&m2);
	cout << "\n";

	cout << "Matrix sum:\n";
	matrix_sum(&m1, &m2, &m3);
	matrix_print(&m3);
	cout << "\n";

	cout << "MAtrix difference:\n";
	matrix_diff(&m1, &m2, &m3);
	matrix_print(&m3);
	cout << "\n";


	cout << "Matrix product\n";
	matrix_prod(&m1, &m2, &m3);
	matrix_print(&m3);
	cout << "\n";

	cout << "Transposed matrix\n";
	matrix_transpose(&m1, &m3);
	matrix_print(&m3);
	cout << "\n";


	matrix_delete(&m1);
	matrix_delete(&m2);
	matrix_delete(&m3);
}