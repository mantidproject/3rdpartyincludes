// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BRepBuilderAPI_MakeShape_HeaderFile
#define _BRepBuilderAPI_MakeShape_HeaderFile

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
#ifndef _TopTools_ListOfShape_HeaderFile
#include <TopTools_ListOfShape.hxx>
#endif
#ifndef _BRepBuilderAPI_Command_HeaderFile
#include <BRepBuilderAPI_Command.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
class StdFail_NotDone;
class TopoDS_Shape;
class TopTools_ListOfShape;


//! This    is  the  root     class for     all  shape <br>
//!          constructions.  It stores the result. <br>
//! <br>
//!          It  provides deferred methods to trace the history <br>
//!          of sub-shapes. <br>
class BRepBuilderAPI_MakeShape  : public BRepBuilderAPI_Command {
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT   virtual  void Delete() ;
Standard_EXPORT virtual ~BRepBuilderAPI_MakeShape(){Delete() ; }
  //! This is  called by  Shape().  It does  nothing but <br>
//!          may be redefined. <br>
  Standard_EXPORT   virtual  void Build() ;
  //! Returns a shape built by the shape construction algorithm. <br>
//! Raises exception StdFail_NotDone if the shape was not built. <br>
  Standard_EXPORT    const TopoDS_Shape& Shape() const;
Standard_EXPORT operator TopoDS_Shape() const;
  //! Returns the  list   of shapes generated   from the <br>
//!          shape <S>. <br>
  Standard_EXPORT   virtual const TopTools_ListOfShape& Generated(const TopoDS_Shape& S) ;
  //! Returns the list  of shapes modified from the shape <br>
//!          <S>. <br>
  Standard_EXPORT   virtual const TopTools_ListOfShape& Modified(const TopoDS_Shape& S) ;
  //! Returns true if the shape S has been deleted. <br>
  Standard_EXPORT   virtual  Standard_Boolean IsDeleted(const TopoDS_Shape& S) ;





protected:

  
  Standard_EXPORT   BRepBuilderAPI_MakeShape();


TopoDS_Shape myShape;
TopTools_ListOfShape myGenerated;


private:





};





// other Inline functions and methods (like "C++: function call" methods)


#endif
