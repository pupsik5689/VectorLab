#pragma once
#include <iostream>

template<class T>
class TVector
{
public:
  //TVector();
  TVector(int n, T v);
  TVector(int n = 1);
  TVector(TVector<T>& p);
  ~TVector();

  int GetLen();
  T GetData(int ind);

  int CountSymb(T l);
  void PosSymb(T l);

  void BubbleSort();
  void Vstavki();
  void QuickSort();

  T& operator [] (int i);
  TVector<T>& operator = (const TVector<T>& p);
  TVector<T> operator + (TVector<T>& p);
  TVector<T> operator - (TVector<T>& p);

  TVector<T> operator * (const TVector<T>& p);
  TVector<T> operator * (const T p);

  TVector<T> operator / (const TVector<T>& p);
  TVector<T> operator / (const T p);
  bool operator == (const TVector<T>& p);

protected:
  int len;
  T* data;
};

template<class T>
inline TVector<T>::TVector(int n, T v)
{
  data = new T[n];
  len = n;
  for (int i = 0; i < n; i++)
    data[i] = v;
}

template<class T>
inline TVector<T>::TVector(int n)
{
  data = new T[n];
  len = n;

}

template<class T>
inline TVector<T>::TVector(TVector<T>& p)
{
  data = new T[p.len];
  len = p.len;
  for (int i = 0; i < len; i++)
    data[i] = p.GetData(i);
}

template<class T>
inline TVector<T>::~TVector()
{
  if (data != 0)
    delete data;
  data = 0;
}

template<class T>
inline int TVector<T>::GetLen()
{
  return len;
}

template<class T>
inline T TVector<T>::GetData(int ind)
{
  return data[ind];
}

template<class T>
inline int TVector<T>::CountSymb(T l)
{
  int res = 0;

  for (int i = 0; i < len; i ++)
    if (data[i] == l)
    {
      res += 1;
    }

  return res;
}

template<class T>
inline void TVector<T>::PosSymb(T l)
{
  for (int i = 0; i < len; i++)
  {
    if (data[i] == l)
      std::cout << i <<"\t";
  }

}

template<class T>
inline void TVector<T>::BubbleSort()
{
  T tmp;

  for (int i = 0; i < len; i++)
    for (int j = 0; j < len - i - 1; j++)
      if (data[j] > data[j + 1])
      {
        tmp = data[j];
        data[j] = data[j + 1];
        data[j + 1] = tmp;
      }
}

template<class T>
inline void TVector<T>::Vstavki()
{
  T tmp = 0;
  int j;
  for (int i = 1; i < len; i++)
  {
    tmp = data[i];
    j = i - 1;
    while ((j >= 0) && (data[j] > tmp))
    {
      data[j + 1] = data[j];
      j--;
    }
    data[j + 1] = tmp;
  }
}

template<class T>
inline void TVector<T>::QuickSort()
{
  QuickPart(data, len);
}

template<class T>
inline void QuickPart(T* mas, int _len)
{
  int i = 0;
  int j = _len - 1;
  T tmp = 0;
  T x = mas[(int)(_len/2)];

  do
  {
    while (mas[i] < x) i++;
    while (mas[j] > x) j--;

    if (i <= j)
    {
      tmp = mas[i];
      mas[i] = mas[j];
      mas[j] = tmp;
      i++;
      j--;
    }
  } while (i <= j);

  if (j > 0)
    QuickPart(mas, j+1);
  
  if (i < _len)
    QuickPart(&mas[i], _len - i);


}

template<class T>
inline T & TVector<T>::operator[](int i)
{
  return data[i];
}

template<class T>
inline TVector<T>& TVector<T>::operator=(const TVector<T>& p)
{
  len = p.len;
  data = new T[len];
  
  for (int i = 0; i < len; i++)
    data[i] = p.data[i];
  return *this;
}

template<class T>
inline TVector<T> TVector<T>::operator+(TVector<T>& p)
{
  if (len == p.len)
  {
    TVector <T> res(this->len);

    for (int i = 0; i < len; i++)
      res[i] = data[i] + p[i];

    return res;
  }
  else throw std::out_of_range("out");
}

template<class T>
inline TVector<T> TVector<T>::operator-(TVector<T>& p)
{
  if (len == p.len)
  {
    TVector <T> res(this->len);

    for (int i = 0; i < len; i++)
      res[i] = data[i] - p[i];

    return res;
  }
  else throw std::out_of_range("out!");
}

template<class T>
inline TVector<T> TVector<T>::operator*(const TVector<T>& p)
{
  TVector <T> res(this->len);
  if (len == p.len)
  {
    for (int i = 0; i < len; i++)
      res[i] = data[i] * p.data[i];

    return res;
  }
  else throw std::out_of_range("out!");
}

template<class T>
inline TVector<T> TVector<T>::operator*(const T p)
{
  TVector <T> res(this->len);

  for (int i = 0; i < len; i++)
    res[i] = data[i] * p;
  return res;
}

template<class T>
inline TVector<T> TVector<T>::operator/(const TVector<T>& p)
{
  TVector <T> res(this->len);
  if (len == p.len)
  {
    for (int i = 0; i < len; i++)
      res[i] = data[i] / p.data[i];

    return res;
  }
  else throw out_of_range("out!");
}

template<class T>
inline TVector<T> TVector<T>::operator/(const T p)
{
  TVector <T> res(this->len);

  for (int i = 0; i < len; i++)
    res[i] = data[i] / p;
  return res;
}

template<class T>
inline bool TVector<T>::operator==(const TVector<T>& p)
{
  for (int i = 0; i < len; i++)
  {
    if (data[i] != p.data[i])
      return false;
  }
  return true;
}

template<class T>
std::ostream & operator<<(std::ostream & o, TVector<T>& p)
{
  for (int i = 0; i < p.GetLen(); i++)
    o << p[i] << "\t";

  return o;
}

template<class T>
std::istream & operator>>(std::istream & is, TVector<T>& p)
{
  int len;
  is >> len;
  TVector<T> res(len);
  for (int i = 0; i < len; i++)
    is >> res[i];

  p = res;

  return is;
}