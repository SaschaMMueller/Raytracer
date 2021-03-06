
#ifndef __MATRIX_H
#define __MATRIX_H
#include <string>
namespace raytracer 
{
	namespace math
	{
		template< class T, unsigned int ROWS, unsigned int COLUMNS > class Matrix;

		template< class T, unsigned int ROWS, unsigned int COLUMNS >
		bool operator==(const Matrix<T,ROWS,COLUMNS>& lhs, const Matrix<T,ROWS,COLUMNS>& rhs) 
		{
		
			for(unsigned int i = 0;i < ROWS; i++)
			{
				for(unsigned int j = 0 ; j <  COLUMNS; j++)
				{
					if( lhs.Get(i,j) != rhs.Get(i,j) )
					{
						return false;
					}
				}
			}

			return true;
		}

		template< class T, unsigned int ROWS, unsigned int COLUMNS >
		bool operator!=(const Matrix<T,ROWS,COLUMNS>& lhs, const Matrix<T,ROWS,COLUMNS>& rhs) 
		{
			return !( rhs == lhs);
		}

		template< class T, unsigned int ROWS, unsigned int COLUMNS, unsigned int COLUMNS2 >
		Matrix<T,ROWS,COLUMNS2> operator*(const Matrix<T,ROWS,COLUMNS>& lhs, const Matrix<T,COLUMNS,COLUMNS2>& rhs) 
		{
			Matrix<T,ROWS,COLUMNS2> tempMatrix(0);
			for(unsigned int i = 0; i < ROWS; i++)
			{
				for(unsigned int j = 0; j < COLUMNS2; j++)
				{
					for( unsigned int k = 0; k < COLUMNS; k++)
					{
						tempMatrix.Set(i,j, tempMatrix.Get(i,j) + lhs.Get(i,k) * rhs.Get(k,j));
					}
				}
			}
			return tempMatrix;
		}

		template< class T, unsigned int ROWS, unsigned int COLUMNS >
		Matrix<T,ROWS,COLUMNS> operator*(const Matrix<T,ROWS,COLUMNS>& lhs, const T& rhs) 
		{
			Matrix<T,ROWS,COLUMNS> tempMatrix(0);
			for(unsigned int i = 0; i < ROWS; i++)
			{
				for(unsigned int j = 0; j < COLUMNS; j++)
				{
					tempMatrix.Set(i,j, lhs.Get(i,j) * rhs);
				}
			}
			return tempMatrix;
		}

		template< class T, unsigned int ROWS, unsigned int COLUMNS >
		Matrix<T,ROWS,COLUMNS> operator/(const Matrix<T,ROWS,COLUMNS>& lhs, const T& rhs) 
		{
			Matrix<T,ROWS,COLUMNS> tempMatrix(0);
			for(unsigned int i = 0; i < ROWS; i++)
			{
				for(unsigned int j = 0; j < COLUMNS; j++)
				{
					tempMatrix.Set(i,j, lhs.Get(i,j) / rhs);
				}
			}
			return tempMatrix;
		}

		template< class T, unsigned int ROWS, unsigned int COLUMNS >
		Matrix<T,ROWS,COLUMNS> operator*(const T& lhs, const Matrix<T,ROWS,COLUMNS>& rhs) 
		{
			Matrix<T,ROWS,COLUMNS> tempMatrix(0);
			for(unsigned int i = 0; i < ROWS; i++)
			{
				for(unsigned int j = 0; j < COLUMNS; j++)
				{
					tempMatrix.Set(i,j, lhs * rhs.Get(i,j));
				}
			}
			return tempMatrix;
		}



		template< class T, unsigned int ROWS, unsigned int COLUMNS >
		Matrix<T,ROWS,COLUMNS> operator+(const Matrix<T,ROWS,COLUMNS>& lhs, const Matrix<T,ROWS,COLUMNS>& rhs) 
		{
			Matrix<T,ROWS,COLUMNS> tempMatrix(0);
			for(unsigned int i = 0; i < ROWS; i++)
			{
				for(unsigned int j = 0; j < COLUMNS; j++)
				{
					tempMatrix.Set(i,j, lhs.Get(i,j) + rhs.Get(i,j));
				}
			}
			return tempMatrix;
		}

		template< class T, unsigned int ROWS, unsigned int COLUMNS >
		Matrix<T,ROWS,COLUMNS> operator-(const Matrix<T,ROWS,COLUMNS>& lhs, const Matrix<T,ROWS,COLUMNS>& rhs) 
		{
			Matrix<T,ROWS,COLUMNS> tempMatrix(0);
			for(unsigned int i = 0; i < ROWS; i++)
			{
				for(unsigned int j = 0; j < COLUMNS; j++)
				{
					tempMatrix.Set(i,j, lhs.Get(i,j) - rhs.Get(i,j));
				}
			}
			return tempMatrix;
		}

		template< class T, unsigned int ROWS, unsigned int COLUMNS > class Matrix
		{
		private:
			T m[ROWS * COLUMNS];

		public:
			Matrix(const T& v)
			{
				for (unsigned int i = 0; i < ROWS ; i++ )
				{
					for (unsigned int j = 0; j < COLUMNS; j++ )
					{
						if( i == j)
						{
							this->Set(i, j, v);
						}

						else
						{
							this->Set(i, j, 0);
						}
					}
				}
			}

			const T& Get (const unsigned int row, const unsigned int column ) const
			{
				return m[column + (row * COLUMNS)];
			}

			void Set (const unsigned int row, const unsigned int column, const T& v )
			{
				m[column + (row * COLUMNS)] = v;
			}

			Matrix<T,ROWS,COLUMNS>& operator+= (const Matrix<T,ROWS,COLUMNS>& rhs)
			{
				for (unsigned int i = 0; i < ROWS ; i++ )
				{
					for (unsigned int j = 0; j < COLUMNS; j++ )
					{
						this->Set(i, j, this->Get(i, j) + rhs.Get(i,j));
					}
				}
				return *this;
			}

			Matrix<T,ROWS,COLUMNS>& operator-= (const Matrix<T,ROWS,COLUMNS>& rhs)
			{
				for (unsigned int i = 0; i < ROWS ; i++ )
				{
					for (unsigned int j = 0; j < COLUMNS; j++ )
					{
						this->Set(i, j, this->Get(i, j) - rhs.Get(i,j));
					}
				}
				return *this;
			}

			Matrix<T,ROWS,COLUMNS>& operator*= (const Matrix<T,COLUMNS,COLUMNS>& rhs)
			{
				Matrix <T,ROWS,COLUMNS> TempMatrix(0);
				for (unsigned int i = 0; i < ROWS ; i++ )
				{
					for (unsigned int j = 0; j < COLUMNS; j++ )
					{

						for (unsigned int k = 0; k < COLUMNS; k++ )
						{
							TempMatrix.Set(i,j, TempMatrix.Get(i, j ) + (this->Get(i, k) * rhs.Get(k, j)));
						}
					}
				}
				*this = TempMatrix;
				return *this;
			}

			Matrix<T,ROWS,COLUMNS>& operator*= (const T& rhs)
			{
				
				for (unsigned int i = 0; i < ROWS ; i++ )
				{
					for (unsigned int j = 0; j < COLUMNS; j++ )
					{
						this->Set(i,j,this->Get(i,j) * rhs );
					}
				}

				return *this;
			}

			Matrix<T,ROWS,COLUMNS>& operator/= (const T& rhs)
			{
				
				for (unsigned int i = 0; i < ROWS ; i++ )
				{
					for (unsigned int j = 0; j < COLUMNS; j++ )
					{
						this->Set(i,j,this->Get(i,j) / rhs );
					}
				}

				return *this;
			}

			Matrix<T,COLUMNS,ROWS> GetTransposed() const
			{
				Matrix <T,COLUMNS,ROWS> TempMatrix(0);

				for(int i = 0; i < ROWS; i++)
				{
					for(int j = 0; j < COLUMNS; j++)
					{
						TempMatrix.Set(j, i, this->Get(i,j));
					}
				}

				return TempMatrix;
			}

			Matrix<T,1,COLUMNS> GetRow( const unsigned int row) const
			{
				Matrix <T,1,COLUMNS> TempMatrix(0);

				for(int i = 0; i < COLUMNS; i++)
					{
						TempMatrix.Set(0, i, this->Get(row,i));
					}

				return TempMatrix;
			}

			void SetRow( const unsigned int row, const Matrix<T,1,COLUMNS>& newRow)
			{
				for(int i = 0; i < COLUMNS; i++)
					{
						this->Set(row, i, newRow.Get(0,i));
					}
			}

			Matrix<T,ROWS,1> GetColumn( const unsigned int column) const
			{
				Matrix <T,ROWS,1> TempMatrix(0);

				for(int i = 0; i < ROWS; i++)
					{
						TempMatrix.Set(i, 0, this->Get(i,column));
					}

				return TempMatrix;
			}

			void SetColumn( const unsigned int column, const Matrix<T,ROWS,1>& newColumn)
			{
				for(int i = 0; i < ROWS; i++)
					{
						this->Set(i, column, newColumn.Get(i,0));
					}
			}
			
			friend bool operator== <> (const Matrix<T,ROWS,COLUMNS>& lhs, const Matrix<T,ROWS,COLUMNS>& rhs);
			friend bool operator!= <> (const Matrix<T,ROWS,COLUMNS>& lhs, const Matrix<T,ROWS,COLUMNS>& rhs);

		};

		

		template< class T, unsigned int ROWS, unsigned int COLUMNS >
		static std::wstring ToString(const Matrix<T,ROWS,COLUMNS>& t) 
		{ RETURN_WIDE_STRING(""); }
	}
}



#endif 