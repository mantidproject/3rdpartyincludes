// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _TopoDS_Wire_HeaderFile
#define _TopoDS_Wire_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _TopoDS_Shape_HeaderFile
#include <TopoDS_Shape.hxx>
#endif


//! Describes a wire which <br>
//! - references an underlying wire with the potential to <br>
//!   be given a location and an orientation <br>
//! - has a location for the underlying wire, giving its <br>
//!   placement in the local coordinate system <br>
//! - has an orientation for the underlying wire, in terms <br>
//!   of its geometry (as opposed to orientation in relation to other shapes). <br>
class TopoDS_Wire  : public TopoDS_Shape {
public:

  DEFINE_STANDARD_ALLOC

  //! Undefined Wire. <br>
      TopoDS_Wire();





protected:





private:





};


#include <TopoDS_Wire.lxx>



// other Inline functions and methods (like "C++: function call" methods)


#endif
