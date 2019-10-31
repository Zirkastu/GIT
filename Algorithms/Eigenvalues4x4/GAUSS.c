#include <math.h>
#include <stdio.h>
void glavelem( int, double(*)[5], int, int*);
int Gauss(double(*mas)[5],int n,double*p)
{  
  double x[n]; //Корни системы
  int otv[n]; //Отвечает за порядок корней
  int i, j, k;
  //Сначала все корни по порядку
  for ( i = 0; i < n + 1; i++ )
    otv[i] = i;
  //Прямой ход метода Гаусса
  for ( k = 0; k < n; k++ )
  { //На какой позиции должен стоять главный элемент
    glavelem( k, mas, n, otv ); //Установка главного элемента
    if ( fabs( mas[k] [k] ) < 0.00001 )
    {
      printf( "Система не имеет единственного решения" );
      return ( 0 );
    }
    for ( j = n; j >= k; j-- )
      mas[k] [j] /= mas[k] [k];
    for ( i = k + 1; i < n; i++ )
      for ( j = n; j >= k; j-- )
        mas[i] [j] -= mas[k] [j] * mas[i] [k];
  }
  //Обратный ход
  for ( i = 0; i < n; i++ )
    x[i] = mas[i] [n];
  for ( i = n - 2; i >= 0; i-- )
    for ( j = i + 1; j < n; j++ )
      x[i] -= x[j] * mas[i] [j];
  //Вывод результата
  //printf( "Ответ:\n" );
  for ( i = 0; i < n; i++ )
    for ( j = 0; j < n; j++ )
      if ( i == otv[j] )
      { //Расставляем корни по порядку
        p[i+1]=-x[j];
        break;
      }
  return 0;
}
//----------------------------------------------
//Описание  функции
//----------------------------------------------
void glavelem( int k, double(*mas)[5] , int n, int otv[] )
{
  int i, j, i_max = k, j_max = k;
  double temp;
  //Ищем максимальный по модулю элемент
  for ( i = k; i < n; i++ )
    for ( j = k; j < n; j++ )
      if ( fabs( mas[i_max] [j_max] ) < fabs( mas[i] [j] ) )
      {
        i_max = i;
        j_max = j;
      }
  //Переставляем строки
  for ( j = k; j < n + 1; j++ )
  {
    temp = mas[k] [j];
    mas[k] [j] = mas[i_max] [j];
    mas[i_max] [j] = temp;
  }
  //Переставляем столбцы
  for ( i = 0; i < n; i++ )
  {
    temp = mas[i] [k];
    mas[i] [k] = mas[i] [j_max];
    mas[i] [j_max] = temp;
  }
  //Учитываем изменение порядка корней
  i = otv[k];
  otv[k] = otv[j_max];
  otv[j_max] = i;
}
