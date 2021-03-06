// Copyright (c) 1998-1999 Matra Datavision
// Copyright (c) 1999-2014 OPEN CASCADE SAS
//
// This file is part of Open CASCADE Technology software library.
//
// This library is free software; you can redistribute it and/or modify it under
// the terms of the GNU Lesser General Public License version 2.1 as published
// by the Free Software Foundation, with special exception defined in the file
// OCCT_LGPL_EXCEPTION.txt. Consult the file LICENSE_LGPL_21.txt included in OCCT
// distribution for complete text of the license and disclaimer of any warranty.
//
// Alternatively, this file may be used under the terms of Open CASCADE
// commercial license or contractual agreement.

//============================================================================
//==== Titre: Standard_ExtString.hxx
//==== 
//==== Implementation:  This is a primitive type implementadef with typedef
//====        typedef short* Standard_ExtString;
//============================================================================

#ifndef _Standard_ExtString_HeaderFile
#define _Standard_ExtString_HeaderFile


#ifndef _Standard_TypeDef_HeaderFile
#include <Standard_TypeDef.hxx>
#endif

class Handle_Standard_Type;

__Standard_API const Handle_Standard_Type& Standard_ExtString_Type_();
//class Standard_OStream;
//void ShallowDump (const Standard_ExtString, Standard_OStream& );
//============================================================================
//==== ShallowCopy: Returns a CString
//============================================================================
inline Standard_ExtString ShallowCopy (const Standard_ExtString Value)
{
  return Value;
}

//============================================================================
//==== HashCode : Returns a HashCode ExtString
//============================================================================
__Standard_API Standard_Integer HashCode (const Standard_ExtString, const Standard_Integer);

#endif
