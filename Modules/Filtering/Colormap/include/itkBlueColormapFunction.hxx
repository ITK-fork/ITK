/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#ifndef __itkBlueColormapFunction_hxx
#define __itkBlueColormapFunction_hxx

#include "itkBlueColormapFunction.h"

namespace itk
{
namespace Function
{
template< class TScalar, class TRGBPixel >
typename BlueColormapFunction< TScalar, TRGBPixel >::RGBPixelType
BlueColormapFunction< TScalar, TRGBPixel >
::operator()(const TScalar & v) const
{
  // Map the input scalar between [0, 1].
  RealType value = this->RescaleInputValue(v);

  // Set the rgb components after rescaling the values.
  RGBPixelType pixel;
  NumericTraits<TRGBPixel>::SetLength(pixel, 3);

  pixel[0] = 0;
  pixel[1] = 0;
  pixel[2] = this->RescaleRGBComponentValue(value);

  return pixel;
}
} // end namespace Function
} // end namespace itk

#endif
