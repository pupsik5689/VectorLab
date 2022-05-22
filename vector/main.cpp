#include <iostream>
#include "Vector.h"
#include "Matrix.h"

int main()
{
  TVector<int> a(5, 4);
  TVector<int> b(5, 4);
  TVector<int> c(1);

  std::cout << a << "\n";

  c = a + b;
  c = a - b;
  std::cout << c <<"\n";
  c = a * 2;
  std::cout << c << "\n";

  if (a == b)
    std::cout <<"YES\n";
  if (a == c)
  {
    std::cout << "AAAA\n";
  } 
  else std::cout << "NO\n";

  c = a * b * b;
  std::cout << c << "\n";

  std::cout << a[0] <<"\n";

  TMatrix<int> d(3, 6, 5);
  TMatrix<int> e(d);
  TMatrix<int> o;
  std::cout << d.GetLen() << "\n";

  if (d == e)
  {
    std::cout << "YES\n";
  }
  else
  {
    std::cout << "NO\n";
  }

  o = d;
  if (d == o)
  {
    std::cout << "YES\n";
  }
  else
  {
    std::cout << "NO\n";
  }

  o = d - o;
  o = d * 5;

  //std::cout << d.Col(1) << "\n";;

  /*for (int i = 0; i < d.GetLen(); i++)
    for (int j = 0; j < d.GetLen2(); j++)
      std::cout << d;*/
  TMatrix<int> p(2,2, 3);
  TMatrix<int> pr(2, 3, 2);
  std::cout << "\n";
  o = p * pr;
  std::cout << "\n\n\n";

  std::cout << o[1][1] << "\n\n";

  std::cout << d << "\n\n\n\n\n";

  TVector<int> v(3, 2);
  TMatrix<int> vv(3, 1, 1);
  std::cout << vv * v << "\n\n\n\n\n";
  //std::cin >> v;
  //std::cin >> o;
  //o.PosSymbM(2);
  //std::cin >> d;
  //std::cout << o * d << "\n\n";
  //std::cout <<  << "\n\n";

  //std::cin >> a;
  //std::cout << a.CountSymb(2) << "\n\n";
  
  //a.PosSymb(2);
  //a.BubbleSort();
  //a.Vstavki();
  //a.QuickSort();

  //std::cout << a;

  return 0;
}




