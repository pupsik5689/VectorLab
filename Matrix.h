#pragma once
#include "Vector.h"

template<class T>
class TMatrix : public TVector<T>
{
public:
  TMatrix();
  TMatrix(const int n1, const int n2);
  TMatrix(const int n1, const int n2, const T l);
  TMatrix(const TMatrix<T>& m);
  ~TMatrix();

  int GetLen2();
  T* GetElement(int ind1, int ind2);

  int CountSymbM(T l);
  void PosSymbM(T l);



  bool operator == (const TMatrix<T>& m);
  TMatrix<T>& operator = (const TMatrix<T>& m);
  TMatrix<T> operator + (const TMatrix<T>& m);
  TMatrix<T> operator - (const TMatrix<T>& m);
  TMatrix<T> operator * (const T a);
  TMatrix<T> operator * (const TMatrix<T>& m);
  TMatrix<T> operator * (TVector<T>& m);
  TVector<T>& operator [] (int i);

protected: 
  int len2;
  TVector<T>* datam;
};

template<class T>
inline TMatrix<T>::TMatrix()
{
  len = 0;
  len2 = 0;
  datam = 0;
}

template<class T>
inline TMatrix<T>::TMatrix(int n1, int n2)
{
  len = n2;
  len2 = n1; datam = new TVector<T>[len2];
  for (int j = 0; j < len2; j++)
    datam[j] = TVector<T>(len, 0);
}

template<class T>
inline TMatrix<T>::TMatrix(const int n1, const int n2, const T l)
{
  len = n2;
  len2 = n1; datam = new TVector<T>[len2]; 
  for (int j = 0; j < len2; j++)
    datam[j] = TVector<T>(len, l);
}

template<class T>
inline TMatrix<T>::TMatrix(const TMatrix<T>& m)
{
  this->len = m.len;
  this->len2 = m.len2;
  datam = new TVector<T>[len2];
  for (int i = 0; i < this->len2; i++) 
    datam[i] = m.datam[i]; 
  
}

template<class T>
inline TMatrix<T>::~TMatrix()
{
  len = 0;
  len2 = 0;
  delete[] datam;
  datam = 0;
}

template<class T>
inline int TMatrix<T>::GetLen2()
{
  return len2;
}

template<class T>
inline T * TMatrix<T>::GetElement(int ind1, int ind2)
{
  return datam[ind2][ind1];
}

template<class T>
inline int TMatrix<T>::CountSymbM(T l)
{
  int res = 0;

  for (int i = 0; i < len2; i++)
    for (int j = 0; j < len; j++)
      if (datam[i][j] == l)
        res += 1;

  return res;
}

template<class T>
inline void TMatrix<T>::PosSymbM(T l)
{
  int res;
  for (int i = 0; i < len2; i++)
  {
    for (int j = 0; j < len; j++)
      if (datam[i][j] == l)
        std::cout << "[" << i << "][" << j << "]\t";
  
  }

}

template<class T>
inline bool TMatrix<T>::operator==(const TMatrix<T>& m)
{
  if ((len == m.len) && (len2 == m.len2))
  {
    bool f = false;
    for (int i = 0; i < len2; i++)
      if (datam[i] == m.datam[i])
      {
        f = true;
      }
      else
      {
        return false;
      }

    return true;
  }
  return false;
}

template<class T>
inline TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T>& m)
{
  len = m.len;
  len2 = m.len2;
  datam = new TVector<T>[len2];
  for (int i = 0; i < len2; i++)
  {
    datam[i] = m.datam[i];
  }
  return *this;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator+(const TMatrix<T>& m)
{
  if ((len == m.len) && (len2 == m.len2))
  {
    TMatrix<T> a(len2, len, 0);
    for (int i = 0; i < len2; i++)
      a.datam[i] = datam[i] + m.datam[i];
    
    return a;
  }
  else
    throw std::out_of_range("Error");
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator-(const TMatrix<T>& m)
{
  if ((len == m.len) && (len2 == m.len2))
  {
    TMatrix<T> a(len2, len, 0);
    for (int i = 0; i < len2; i++)
      a.datam[i] = datam[i] - m.datam[i];
   
    return a;
  }
  else
    throw std::out_of_range("Error");
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator*(const T a)
{
  TMatrix<T> mat = *this;
  for (int i = 0; i < len2; i++)
  {
    mat.datam[i] = datam[i] * a;
    std::cout << mat.datam[i] << "\n";
  }
  return TMatrix<T>();
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator*(const TMatrix<T>& m)
{
  if (len == m.len2)
  {
    TMatrix<T> res(len2, m.len, 0);

    for (int i = 0; i < len2; i++)
    {
      for (int j = 0; j < m.len; j++)
      {
        for (int k = 0; k < len; k++)
          res.datam[i][j] += this->datam[i][k] *  m.datam[k][j];
        
      }
      //std::cout << res.datam[i]<<"\n";
    }
      return res;
  }
  else throw std::out_of_range("Error");
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator*(TVector<T>& m)
{
  if (len == 1) 
  {
    TMatrix<T> res(len2, m.GetLen(), 0);
    for (int i = 0; i < len2; i++)
    {
      for (int j = 0; j < m.GetLen(); j++)
      {
        for (int k = 0; k < len; k++)
          res.datam[i][j] += this->datam[i][k] * m[k];

      }
      //std::cout << res.datam[i] << "\n";
    }
    return res;
  }
  else throw std::out_of_range("Error");
  
}

template<class T>
inline TVector<T> & TMatrix<T>::operator[](int i)
{
  return datam[i];
}

template<class T>
std::ostream & operator<<(std::ostream & o, TMatrix<T>& p)
{
  for (int i = 0; i < p.GetLen2(); i++)
    o << p[i] << "\n";

  return o;
}

template<class T>
std::istream & operator>>(std::istream & is, TMatrix<T>& p)
{
  int len; int len2;
  is >> len2 >> len;

  TMatrix<T> res(len2, len, 0);
  for (int i = 0; i < len2; i++)
    for (int j = 0; j < len; j++)
      is >> res[i][j];

  p = res;

  return is;
}