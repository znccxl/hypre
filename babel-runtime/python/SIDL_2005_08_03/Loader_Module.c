/*
 * File:          Loader_Module.c
 * Symbol:        SIDL.Loader-v0.8.1
 * Symbol Type:   class
 * Babel Version: 0.8.0
 * Release:       $Name$
 * Revision:      @(#) $Id$
 * Description:   implement a C extension type for a SIDL extendable
 * 
 * Copyright (c) 2000-2002, The Regents of the University of California.
 * Produced at the Lawrence Livermore National Laboratory.
 * Written by the Components Team <components@llnl.gov>
 * All rights reserved.
 * 
 * This file is part of Babel. For more information, see
 * http://www.llnl.gov/CASC/components/. Please read the COPYRIGHT file
 * for Our Notice and the LICENSE file for the GNU Lesser General Public
 * License.
 * 
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License (as published by
 * the Free Software Foundation) version 2.1 dated February 1999.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the IMPLIED WARRANTY OF
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the terms and
 * conditions of the GNU Lesser General Public License for more details.
 * 
 * You should have recieved a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 * babel-version = 0.8.0
 */

/*
 * THIS CODE IS AUTOMATICALLY GENERATED BY THE BABEL
 * COMPILER. DO NOT EDIT THIS!
 * 
 * This file contains the implementation of a Python C
 * extension type (i.e. a Python type implemented in C).
 * This extension type provides Python interface to the
 * SIDL type SIDL.Loader.
 */


/**
 * Symbol "SIDL.Loader" (version 0.8.1)
 * 
 * Class <code>Loader</code> manages dyanamic loading and symbol name
 * resolution for the SIDL runtime system.  The <code>Loader</code> class
 * manages a library search path and keeps a record of all libraries
 * loaded through this interface, including the initial "global" symbols
 * in the main program.  Unless explicitly set, the search path is taken
 * from the environment variable SIDL_DLL_PATH, which is a semi-colon
 * separated sequence of URIs as described in class <code>DLL</code>.
 */
#define SIDL_Loader_INTERNAL 1
#include "SIDL_Loader_Module.h"
#ifndef included_SIDL_Loader_IOR_h
#include "SIDL_Loader_IOR.h"
#endif
#include "SIDLObjA.h"
#include "SIDLPyArrays.h"
#include "Numeric/arrayobject.h"
#ifndef included_SIDL_Loader_h
#include "SIDL_Loader.h"
#endif
#ifndef included_SIDL_header_h
#include "SIDL_header.h"
#endif
#ifndef included_SIDL_interface_IOR_h
#include "SIDL_interface_IOR.h"
#endif
#include "SIDL_BaseInterface_Module.h"
#include "SIDL_BaseClass_Module.h"
#include "SIDL_ClassInfo_Module.h"
#include "SIDL_DLL_Module.h"
#include <stdlib.h>
#include <string.h>

static struct SIDL_Loader__sepv *_sepv = NULL;

static const struct SIDL_Loader__external *_implEPV = NULL;

static PyObject *
pStub_Loader_addRef(PyObject *_self, PyObject *_args, PyObject *_kwdict) {
  PyObject *_return_value = NULL;
  struct SIDL_Loader__object *_self_ior =
    ((struct SIDL_Loader__object *)
     SIDL_Cast(_self, "SIDL.Loader"));
  if (_self_ior) {
    static char *_kwlist[] = {
      NULL
    };
    const int _okay = PyArg_ParseTupleAndKeywords(
      _args, _kwdict, 
      "", _kwlist);
    if (_okay) {
      (*(_self_ior->d_epv->f_addRef))(_self_ior);
      _return_value = Py_None;
      Py_INCREF(_return_value);
    }
  }
  else {
    PyErr_SetString(PyExc_TypeError, 
      "self pointer is not a SIDL.Loader");
  }
  return _return_value;
}

static PyObject *
pStub_Loader_deleteRef(PyObject *_self, PyObject *_args, PyObject *_kwdict) {
  PyObject *_return_value = NULL;
  struct SIDL_Loader__object *_self_ior =
    ((struct SIDL_Loader__object *)
     SIDL_Cast(_self, "SIDL.Loader"));
  if (_self_ior) {
    static char *_kwlist[] = {
      NULL
    };
    const int _okay = PyArg_ParseTupleAndKeywords(
      _args, _kwdict, 
      "", _kwlist);
    if (_okay) {
      (*(_self_ior->d_epv->f_deleteRef))(_self_ior);
      _return_value = Py_None;
      Py_INCREF(_return_value);
    }
  }
  else {
    PyErr_SetString(PyExc_TypeError, 
      "self pointer is not a SIDL.Loader");
  }
  return _return_value;
}

static PyObject *
pStub_Loader_isSame(PyObject *_self, PyObject *_args, PyObject *_kwdict) {
  PyObject *_return_value = NULL;
  struct SIDL_Loader__object *_self_ior =
    ((struct SIDL_Loader__object *)
     SIDL_Cast(_self, "SIDL.Loader"));
  if (_self_ior) {
    struct SIDL_BaseInterface__object* iobj = NULL;
    static char *_kwlist[] = {
      "iobj",
      NULL
    };
    const int _okay = PyArg_ParseTupleAndKeywords(
      _args, _kwdict, 
      "O&", _kwlist,
      (void *)SIDL_BaseInterface__convert, &iobj);
    if (_okay) {
      SIDL_bool _return = (SIDL_bool) 0;
      int _proxy__return;
      _return = (*(_self_ior->d_epv->f_isSame))(_self_ior, iobj);
      _proxy__return = _return;
      _return_value = Py_BuildValue(
        "i",
        _proxy__return);
      SIDL_BaseInterface_deref(iobj);
    }
  }
  else {
    PyErr_SetString(PyExc_TypeError, 
      "self pointer is not a SIDL.Loader");
  }
  return _return_value;
}

static PyObject *
pStub_Loader_queryInt(PyObject *_self, PyObject *_args, PyObject *_kwdict) {
  PyObject *_return_value = NULL;
  struct SIDL_Loader__object *_self_ior =
    ((struct SIDL_Loader__object *)
     SIDL_Cast(_self, "SIDL.Loader"));
  if (_self_ior) {
    char* name = NULL;
    static char *_kwlist[] = {
      "name",
      NULL
    };
    const int _okay = PyArg_ParseTupleAndKeywords(
      _args, _kwdict, 
      "z", _kwlist,
      &name);
    if (_okay) {
      struct SIDL_BaseInterface__object* _return = NULL;
      _return = (*(_self_ior->d_epv->f_queryInt))(_self_ior, name);
      _return_value = Py_BuildValue(
        "O&",
        (void *)SIDL_BaseInterface__wrap, _return);
    }
  }
  else {
    PyErr_SetString(PyExc_TypeError, 
      "self pointer is not a SIDL.Loader");
  }
  return _return_value;
}

static PyObject *
pStub_Loader_isType(PyObject *_self, PyObject *_args, PyObject *_kwdict) {
  PyObject *_return_value = NULL;
  struct SIDL_Loader__object *_self_ior =
    ((struct SIDL_Loader__object *)
     SIDL_Cast(_self, "SIDL.Loader"));
  if (_self_ior) {
    char* name = NULL;
    static char *_kwlist[] = {
      "name",
      NULL
    };
    const int _okay = PyArg_ParseTupleAndKeywords(
      _args, _kwdict, 
      "z", _kwlist,
      &name);
    if (_okay) {
      SIDL_bool _return = (SIDL_bool) 0;
      int _proxy__return;
      _return = (*(_self_ior->d_epv->f_isType))(_self_ior, name);
      _proxy__return = _return;
      _return_value = Py_BuildValue(
        "i",
        _proxy__return);
    }
  }
  else {
    PyErr_SetString(PyExc_TypeError, 
      "self pointer is not a SIDL.Loader");
  }
  return _return_value;
}

static PyObject *
pStub_Loader_getClassInfo(PyObject *_self, PyObject *_args,                   \
  PyObject *_kwdict) {
  PyObject *_return_value = NULL;
  struct SIDL_Loader__object *_self_ior =
    ((struct SIDL_Loader__object *)
     SIDL_Cast(_self, "SIDL.Loader"));
  if (_self_ior) {
    static char *_kwlist[] = {
      NULL
    };
    const int _okay = PyArg_ParseTupleAndKeywords(
      _args, _kwdict, 
      "", _kwlist);
    if (_okay) {
      struct SIDL_ClassInfo__object* _return = NULL;
      _return = (*(_self_ior->d_epv->f_getClassInfo))(_self_ior);
      _return_value = Py_BuildValue(
        "O&",
        (void *)SIDL_ClassInfo__wrap, _return);
    }
  }
  else {
    PyErr_SetString(PyExc_TypeError, 
      "self pointer is not a SIDL.Loader");
  }
  return _return_value;
}

static PyObject *
pStub_Loader_setSearchPath(PyObject *_ignored, PyObject *_args,               \
  PyObject *_kwdict) {
  PyObject *_return_value = NULL;
  char* path_name = NULL;
  static char *_kwlist[] = {
    "path_name",
    NULL
  };
  const int _okay = PyArg_ParseTupleAndKeywords(
    _args, _kwdict, 
    "z", _kwlist,
    &path_name);
  if (_okay) {
    (*(_sepv->f_setSearchPath))(path_name);
    _return_value = Py_None;
    Py_INCREF(_return_value);
  }
  return _return_value;
}

static PyObject *
pStub_Loader_getSearchPath(PyObject *_ignored, PyObject *_args,               \
  PyObject *_kwdict) {
  PyObject *_return_value = NULL;
  static char *_kwlist[] = {
    NULL
  };
  const int _okay = PyArg_ParseTupleAndKeywords(
    _args, _kwdict, 
    "", _kwlist);
  if (_okay) {
    char* _return = NULL;
    _return = (*(_sepv->f_getSearchPath))();
    _return_value = Py_BuildValue(
      "z",
      _return);
    free((void *)_return);
  }
  return _return_value;
}

static PyObject *
pStub_Loader_addSearchPath(PyObject *_ignored, PyObject *_args,               \
  PyObject *_kwdict) {
  PyObject *_return_value = NULL;
  char* path_fragment = NULL;
  static char *_kwlist[] = {
    "path_fragment",
    NULL
  };
  const int _okay = PyArg_ParseTupleAndKeywords(
    _args, _kwdict, 
    "z", _kwlist,
    &path_fragment);
  if (_okay) {
    (*(_sepv->f_addSearchPath))(path_fragment);
    _return_value = Py_None;
    Py_INCREF(_return_value);
  }
  return _return_value;
}

static PyObject *
pStub_Loader_loadLibrary(PyObject *_ignored, PyObject *_args,                 \
  PyObject *_kwdict) {
  PyObject *_return_value = NULL;
  char* uri = NULL;
  static char *_kwlist[] = {
    "uri",
    NULL
  };
  const int _okay = PyArg_ParseTupleAndKeywords(
    _args, _kwdict, 
    "z", _kwlist,
    &uri);
  if (_okay) {
    SIDL_bool _return = (SIDL_bool) 0;
    int _proxy__return;
    _return = (*(_sepv->f_loadLibrary))(uri);
    _proxy__return = _return;
    _return_value = Py_BuildValue(
      "i",
      _proxy__return);
  }
  return _return_value;
}

static PyObject *
pStub_Loader_addDLL(PyObject *_ignored, PyObject *_args, PyObject *_kwdict) {
  PyObject *_return_value = NULL;
  struct SIDL_DLL__object* dll = NULL;
  static char *_kwlist[] = {
    "dll",
    NULL
  };
  const int _okay = PyArg_ParseTupleAndKeywords(
    _args, _kwdict, 
    "O&", _kwlist,
    (void *)SIDL_DLL__convert, &dll);
  if (_okay) {
    (*(_sepv->f_addDLL))(dll);
    _return_value = Py_None;
    Py_INCREF(_return_value);
    SIDL_DLL_deref(dll);
  }
  return _return_value;
}

static PyObject *
pStub_Loader_unloadLibraries(PyObject *_ignored, PyObject *_args,             \
  PyObject *_kwdict) {
  PyObject *_return_value = NULL;
  static char *_kwlist[] = {
    NULL
  };
  const int _okay = PyArg_ParseTupleAndKeywords(
    _args, _kwdict, 
    "", _kwlist);
  if (_okay) {
    (*(_sepv->f_unloadLibraries))();
    _return_value = Py_None;
    Py_INCREF(_return_value);
  }
  return _return_value;
}

static PyObject *
pStub_Loader_lookupSymbol(PyObject *_ignored, PyObject *_args,                \
  PyObject *_kwdict) {
  PyObject *_return_value = NULL;
  char* linker_name = NULL;
  static char *_kwlist[] = {
    "linker_name",
    NULL
  };
  const int _okay = PyArg_ParseTupleAndKeywords(
    _args, _kwdict, 
    "z", _kwlist,
    &linker_name);
  if (_okay) {
    void* _return = NULL;
    _return = (*(_sepv->f_lookupSymbol))(linker_name);
    _return_value = Py_BuildValue(
      "O&",
      (void *)SIDL_Opaque_Create, _return);
  }
  return _return_value;
}

static PyObject *
pStub_Loader_createClass(PyObject *_ignored, PyObject *_args,                 \
  PyObject *_kwdict) {
  PyObject *_return_value = NULL;
  char* sidl_name = NULL;
  static char *_kwlist[] = {
    "sidl_name",
    NULL
  };
  const int _okay = PyArg_ParseTupleAndKeywords(
    _args, _kwdict, 
    "z", _kwlist,
    &sidl_name);
  if (_okay) {
    struct SIDL_BaseClass__object* _return = NULL;
    _return = (*(_sepv->f_createClass))(sidl_name);
    _return_value = Py_BuildValue(
      "O&",
      (void *)SIDL_BaseClass__wrap, _return);
  }
  return _return_value;
}

static PyObject *
_createCast(PyObject *self, PyObject *args) {
  struct SIDL_Loader__object *optarg = NULL;
  int _okay = PyArg_ParseTuple(args, "|O&", (void *)SIDL_Loader__convert,     \
    &optarg);
  if (_okay) {
    if (optarg) {
      (*(optarg->d_epv->f_addRef))(optarg);
    }
    else {
      optarg = (*(_implEPV->createObject))();
    }
    return SIDL_Loader__wrap(optarg);
  }
  return NULL;
}

static PyMethodDef _LoaderModuleMethods[] = {
  { "Loader", _createCast, METH_VARARGS, "Constructor and/or cast method for SIDL.Loader"
   },
  { "addDLL", (PyCFunction)pStub_Loader_addDLL,
  (METH_VARARGS | METH_KEYWORDS),
"\
addDLL(in SIDL.DLL dll)\n\
RETURNS\n\
    None\n\
\n\
\
Append the specified DLL to the beginning of the list of already\n\
loaded DLLs."
   },
  { "addSearchPath", (PyCFunction)pStub_Loader_addSearchPath,
  (METH_VARARGS | METH_KEYWORDS),
"\
addSearchPath(in string path_fragment)\n\
RETURNS\n\
    None\n\
\n\
\
Append the specified path fragment to the beginning of the\n\
current search path.  If the search path has not yet been set\n\
by a call to <code>setSearchPath</code>, then this fragment will\n\
be appended to the path in environment variable SIDL_DLL_PATH."
   },
  { "createClass", (PyCFunction)pStub_Loader_createClass,
  (METH_VARARGS | METH_KEYWORDS),
"\
createClass(in string sidl_name)\n\
RETURNS\n\
   (SIDL.BaseClass _return)\n\
\n\
\
Create an instance of the specified SIDL class.  If the class\n\
constructor cannot be found in one of the already loaded libraries,\n\
then the method will search through the library search path.  A null\n\
object is returned if the symbol could not be resolved."
   },
  { "getSearchPath", (PyCFunction)pStub_Loader_getSearchPath,
  (METH_VARARGS | METH_KEYWORDS),
"\
getSearchPath()\n\
RETURNS\n\
   (string _return)\n\
\n\
\
Return the current search path.  If the search path has not been\n\
set, then the search path will be taken from environment variable\n\
SIDL_DLL_PATH."
   },
  { "loadLibrary", (PyCFunction)pStub_Loader_loadLibrary,
  (METH_VARARGS | METH_KEYWORDS),
"\
loadLibrary(in string uri)\n\
RETURNS\n\
   (bool _return)\n\
\n\
\
Load the specified library if it has not already been loaded.\n\
The URI format is defined in class <code>DLL</code>.  The search\n\
path is not searched to resolve the library name."
   },
  { "lookupSymbol", (PyCFunction)pStub_Loader_lookupSymbol,
  (METH_VARARGS | METH_KEYWORDS),
"\
lookupSymbol(in string linker_name)\n\
RETURNS\n\
   (opaque _return)\n\
\n\
\
Look up the secified symbol name.  If the symbol name cannot be\n\
found in one of the already loaded libraries, then the method will\n\
search through the library search path.  A null is returned if the\n\
symbol could not be resolved."
   },
  { "setSearchPath", (PyCFunction)pStub_Loader_setSearchPath,
  (METH_VARARGS | METH_KEYWORDS),
"\
setSearchPath(in string path_name)\n\
RETURNS\n\
    None\n\
\n\
\
Set the search path, which is a semi-colon separated sequence of\n\
URIs as described in class <code>DLL</code>.  This method will\n\
invalidate any existing search path."
   },
  { "unloadLibraries", (PyCFunction)pStub_Loader_unloadLibraries,
  (METH_VARARGS | METH_KEYWORDS),
"\
unloadLibraries()\n\
RETURNS\n\
    None\n\
\n\
\
Unload all dynamic link libraries.  The library may no longer\n\
be used to access symbol names.  When the library is actually\n\
unloaded from the memory image depends on details of the operating\n\
system."
   },
  { NULL, NULL }
};

static PyMethodDef _LoaderObjectMethods[] = {
  { "addRef", (PyCFunction)pStub_Loader_addRef,
  (METH_VARARGS | METH_KEYWORDS),
"\
addRef()\n\
RETURNS\n\
    None\n\
\n\
\
<p>\n\
Add one to the intrinsic reference count in the underlying object.\n\
Object in <code>SIDL</code> have an intrinsic reference count.\n\
Objects continue to exist as long as the reference count is\n\
positive. Clients should call this method whenever they\n\
create another ongoing reference to an object or interface.\n\
</p>\n\
<p>\n\
This does not have a return value because there is no language\n\
independent type that can refer to an interface or a\n\
class.\n\
</p>"
   },
  { "deleteRef", (PyCFunction)pStub_Loader_deleteRef,
  (METH_VARARGS | METH_KEYWORDS),
"\
deleteRef()\n\
RETURNS\n\
    None\n\
\n\
\
Decrease by one the intrinsic reference count in the underlying\n\
object, and delete the object if the reference is non-positive.\n\
Objects in <code>SIDL</code> have an intrinsic reference count.\n\
Clients should call this method whenever they remove a\n\
reference to an object or interface."
   },
  { "getClassInfo", (PyCFunction)pStub_Loader_getClassInfo,
  (METH_VARARGS | METH_KEYWORDS),
"\
getClassInfo()\n\
RETURNS\n\
   (SIDL.ClassInfo _return)\n\
\n\
\
Return the meta-data about the class implementing this interface."
   },
  { "isSame", (PyCFunction)pStub_Loader_isSame,
  (METH_VARARGS | METH_KEYWORDS),
"\
isSame(in SIDL.BaseInterface iobj)\n\
RETURNS\n\
   (bool _return)\n\
\n\
\
Return true if and only if <code>obj</code> refers to the same\n\
object as this object."
   },
  { "isType", (PyCFunction)pStub_Loader_isType,
  (METH_VARARGS | METH_KEYWORDS),
"\
isType(in string name)\n\
RETURNS\n\
   (bool _return)\n\
\n\
\
Return whether this object is an instance of the specified type.\n\
The string name must be the <code>SIDL</code> type name.  This\n\
routine will return <code>true</code> if and only if a cast to\n\
the string type name would succeed."
   },
  { "queryInt", (PyCFunction)pStub_Loader_queryInt,
  (METH_VARARGS | METH_KEYWORDS),
"\
queryInt(in string name)\n\
RETURNS\n\
   (SIDL.BaseInterface _return)\n\
\n\
\
Check whether the object can support the specified interface or\n\
class.  If the <code>SIDL</code> type name in <code>name</code>\n\
is supported, then a reference to that object is returned with the\n\
reference count incremented.  The callee will be responsible for\n\
calling <code>deleteRef</code> on the returned object.  If\n\
the specified type is not supported, then a null reference is\n\
returned."
   },
  { NULL, NULL }
};

SIDL_Loader__wrap_RETURN
SIDL_Loader__wrap SIDL_Loader__wrap_PROTO {
  return SIDL_Object_Create((struct SIDL_BaseClass__object *) sidlobj,        \
    _LoaderObjectMethods, SIDL_PyStealRef);
}

SIDL_Loader__weakRef_RETURN
SIDL_Loader__weakRef SIDL_Loader__weakRef_PROTO {
  return SIDL_Object_Create((struct SIDL_BaseClass__object *) sidlobj,        \
    _LoaderObjectMethods, SIDL_PyWeakRef);
}

SIDL_Loader_deref_RETURN
SIDL_Loader_deref SIDL_Loader_deref_PROTO {
  if (sidlobj) {
    (*(sidlobj->d_epv->f_deleteRef))(sidlobj);
  }
}

SIDL_Loader__newRef_RETURN
SIDL_Loader__newRef SIDL_Loader__newRef_PROTO {
  return SIDL_Object_Create((struct SIDL_BaseClass__object *) sidlobj,        \
    _LoaderObjectMethods, SIDL_PyNewRef);
}

SIDL_Loader__addRef_RETURN
SIDL_Loader__addRef SIDL_Loader__addRef_PROTO {
  if (sidlobj) {
    (*(sidlobj->d_epv->f_addRef))(sidlobj);
  }
}

SIDL_Loader__convert_RETURN
SIDL_Loader__convert SIDL_Loader__convert_PROTO {
  *sidlobj = SIDL_Cast(obj, "SIDL.Loader");
  if (*sidlobj) {
    (*((*sidlobj)->d_epv->f_addRef))(*sidlobj);
  }
  else if (obj != Py_None) {
    PyErr_SetString(PyExc_TypeError, 
      "argument is not a(n) SIDL.Loader");
    return 0;
  }
  return 1;
}

static int
_convertPython(void *sidlarray, const int *ind, PyObject *pyobj)
{
  struct SIDL_Loader__object *sidlobj;
  if (SIDL_Loader__convert(pyobj, &sidlobj)) {
    SIDL_interface__array_set((struct SIDL_interface__array *)sidlarray,
    ind, (struct SIDL_BaseInterface__object *)sidlobj);
    return FALSE;
  }
  return TRUE;
}

SIDL_Loader__convert_python_array_RETURN
SIDL_Loader__convert_python_array SIDL_Loader__convert_python_array_PROTO {
  int result = 0;
  PyObject *pya = PyArray_FromObject(obj, PyArray_OBJECT, 0, 0);
  *sidlarray = NULL;
  if (pya) {
    if (PyArray_OBJECT == ((PyArrayObject *)pya)->descr->type_num) {
      int dimen, *lower, *upper, *stride;
      if (SIDL_array__extract_python_info
        (pya, &dimen, &lower, &upper, &stride))
      {
          *sidlarray = (struct                                                \
            SIDL_Loader__array*)SIDL_interface__array_createRow
          (dimen, lower, upper);
        free(stride);
        free(upper);
        free(lower);
        result = SIDL_array__convert_python
          (pya, dimen, *sidlarray, _convertPython);
        if (*sidlarray && !result) {
          SIDL_interface__array_deleteRef(
            (struct  SIDL_interface__array *)*sidlarray);
          *sidlarray = NULL;
        }
      }
    }
    Py_DECREF(pya);
  }
  return result;
}

static int
_convertSIDL(void *sidlarray, const int *ind, PyObject **dest)
{
  struct SIDL_Loader__object *sidlobj = (struct SIDL_Loader__object*)
  SIDL_interface__array_get((struct SIDL_interface__array *)
    sidlarray, ind);
  *dest = SIDL_Loader__wrap(sidlobj);
  return (*dest == NULL);
}

SIDL_Loader__convert_sidl_array_RETURN
  SIDL_Loader__convert_sidl_array SIDL_Loader__convert_sidl_array_PROTO       \
    {PyObject *pya = NULL;
  if (sidlarray) {
    const int dimen = SIDL_interface__array_dimen(
      (struct SIDL_interface__array *)sidlarray);
    int i;
    int *lower = (int *)malloc(sizeof(int) * dimen);
    int *upper = (int *)malloc(sizeof(int) * dimen);
    int *numelem = (int *)malloc(sizeof(int) * dimen);
    for(i = 0; i < dimen; ++i) {
      lower[i] = SIDL_interface__array_lower(
        (struct SIDL_interface__array *)sidlarray, i);
      upper[i] = SIDL_interface__array_upper(
        (struct SIDL_interface__array *)sidlarray, i);
      numelem[i] = 1 + upper[i] - lower[i];
    }
    pya = PyArray_FromDims(dimen, numelem, PyArray_OBJECT);
    if (pya) {
      if (!SIDL_array__convert_sidl(pya, dimen, lower, upper,
        numelem, sidlarray, _convertSIDL))
      {
        Py_DECREF(pya);
        pya = NULL;
      }
    }
    free(numelem);
    free(upper);
    free(lower);
  }
  return pya;
}

SIDL_Loader__destroy_sidl_array_RETURN
SIDL_Loader__destroy_sidl_array SIDL_Loader__destroy_sidl_array_PROTO {
  if (sidlarray) {
    SIDL_interface__array_deleteRef(
      (struct SIDL_interface__array *)sidlarray);
  }
}
void
initLoader(void) {
  PyObject *module, *dict, *c_api;
  static void *ExternalAPI[SIDL_Loader__API_NUM];
  module = Py_InitModule3("Loader", _LoaderModuleMethods, "\
\
Class <code>Loader</code> manages dyanamic loading and symbol name\n\
resolution for the SIDL runtime system.  The <code>Loader</code> class\n\
manages a library search path and keeps a record of all libraries\n\
loaded through this interface, including the initial \"global\" symbols\n\
in the main program.  Unless explicitly set, the search path is taken\n\
from the environment variable SIDL_DLL_PATH, which is a semi-colon\n\
separated sequence of URIs as described in class <code>DLL</code>."
  );
  _implEPV = SIDL_Loader__externals();
  if (!_implEPV) {
    Py_FatalError("Cannot load implementation for SIDL class SIDL.Loader");
  }
  dict = PyModule_GetDict(module);
  ExternalAPI[SIDL_Loader__wrap_NUM] = (void*)SIDL_Loader__wrap;
  ExternalAPI[SIDL_Loader__convert_NUM] = (void*)SIDL_Loader__convert;
  ExternalAPI[SIDL_Loader__convert_python_array_NUM] =                        \
    (void*)SIDL_Loader__convert_python_array;
  ExternalAPI[SIDL_Loader__convert_sidl_array_NUM] =                          \
    (void*)SIDL_Loader__convert_sidl_array;
  ExternalAPI[SIDL_Loader__destroy_sidl_array_NUM] =                          \
    (void*)SIDL_Loader__destroy_sidl_array;
  ExternalAPI[SIDL_Loader__weakRef_NUM] = (void*)SIDL_Loader__weakRef;
  ExternalAPI[SIDL_Loader_deref_NUM] = (void*)SIDL_Loader_deref;
  ExternalAPI[SIDL_Loader__newRef_NUM] = (void*)SIDL_Loader__newRef;
  ExternalAPI[SIDL_Loader__addRef_NUM] = (void*)SIDL_Loader__addRef;
  import_SIDLObjA();
  if (PyErr_Occurred()) {
    Py_FatalError("Error importing SIDLObjA module.");
  }
  c_api = PyCObject_FromVoidPtr((void *)ExternalAPI, NULL);
  PyDict_SetItemString(dict, "_C_API", c_api);
  Py_XDECREF(c_api);
  _sepv = (*_implEPV->getStaticEPV)();
  if (PyErr_Occurred()) {
    Py_FatalError("Cannot initialize Python module SIDL.Loader.");
  }
  import_SIDLPyArrays();
  if (PyErr_Occurred()) {
    Py_FatalError("Error importing SIDLPyArrays module.");
  }
  import_array();
  if (PyErr_Occurred()) {
    Py_FatalError("Error importing Numeric Python module.");
  }
  SIDL_BaseInterface__import();
  SIDL_BaseClass__import();
  SIDL_ClassInfo__import();
  SIDL_DLL__import();
}
