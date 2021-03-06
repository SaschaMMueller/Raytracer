#ifndef __SHADERECORD_H
#define __SHADERECORD_H
#include "Ray.h"

namespace raytracer
{
	template< class T > class Geometry;

	template <class T>
	class ShadeRecord
	{
		private:
			math::ColumnVector<T,3> n;
			const Geometry<T>* geometry;
			const Ray<T>* ray;
			T t;
			bool valid;

		public:

			ShadeRecord ()	: geometry ( NULL), ray ( NULL), t(0), valid( false)
			{
				
			}

			const Geometry<T>* GetGeomety() 
			{
				return geometry;
			}
		
			void SetGeometry ( const Geometry<T>* geometry)
			{
				this->geometry = geometry;
			}

			const Ray<T>* GetRay()  const
			{
				return ray;
			}
		
			void SetRay (const Ray<T>* ray)
			{
				this->ray = ray;
			}

			const T& GetT()  const
			{
				return t;
			}
		
			void SetT(const T& t)
			{
				this->t = t;
			}

			const math::ColumnVector< T, 3>& GetN() const
			{
				return n;
			}

			void SetN(const math::ColumnVector< T, 3>& nValue)
			{
				n = nValue;
			}
	
			bool IsValid() const 
			{
				return valid;
			}
		
			void SetValid (const bool valid) 
			{
				this->valid = valid;
			}
	
	
	};

}









#endif