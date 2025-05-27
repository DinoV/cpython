#ifndef Py_INTERNAL_TYPEDMETHODDEF_H
#define Py_INTERNAL_TYPEDMETHODDEF_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef Py_BUILD_CORE
#  error "this header requires Py_BUILD_CORE define"
#endif


// Represents a C type that can be declared in for a function or for a return value.
typedef enum _PyCType {
  _PyCType_Int8,
  _PyCType_Int16,
  _PyCType_Int32,
  _PyCType_Int64,
  _PyCType_SSizeT,
  
  _PyCType_UInt8,
  _PyCType_UInt16,
  _PyCType_UInt32,
  _PyCType_UInt64,
  _PyCType_SizeT,
  
  _PyCType_Single,
  _PyCType_Double,

  _PyCType_Char,
  _PyCType_UChar,
 
  _PyCType_Bool,
  _PyCType_Void,

  _PyCType_Object,
  _PyCType_Int,
  _PyCType_Unicode,
  _PyCType_Str, // const char *
  _PyCType_Slice,
  _PyCType_Bytes,
  _PyCType_ByteArray,
  _PyCType_Buffer,
  _PyCType_Complex,
  
  _PyCType_Error,

  _PyCType_TypeParam,
} _PyCType;

typedef struct _PySigElemType {
  // Known type
  _PyCType sig_type : 8;
  // Value is optional and can be specified as None
  bool optional : 1;
  // Type parameter, 0 is self, 1+ indicates generic type
  int type_param: 7;
} _PySigElemType;

typedef union {
  void *dfv_ptr;
  int32_t dfv_int32;
  PyObject* dfv_object;
  Py_ssize_t dfv_ssize_t;
} _PySigDefaultValue;

typedef struct {
  // The C function that conforms to the specified signature
  void* tmd_cmeth; 
  // The normal entry point which will parse arguments
  PyCFunction tmd_meth;
  // The tmd_flags for the normal entry point
  int tmd_flags;
  // The function return type
  _PyCType tmd_ret;
  // The number of arguments specified in the signature
  Py_ssize_t tmd_argcnt;
  Py_ssize_t tmd_minargs;
  // The function signature
  const _PySigElemType* tmd_sig;
  const char* const* tmd_kwnames;
  const _PySigDefaultValue* tmd_defaults;
  const char tmd_doc[];
} _PyTypedMethodDef;


// These are signatures which are more common, we support some in
// the specializing interpreter and JIT.
extern const _PySigElemType _PyMethodObjectSig2[];
extern const _PySigElemType _PyMethodObjectSig3[];
extern const _PySigElemType _PyMethodObjectSig4[];
extern const _PySigElemType _PyMethodObjectSig5[];
extern const _PySigElemType _PyMethodObjectSig6[];

typedef PyObject* (*_PyMethodObjectSig3Func)(PyObject*, PyObject*, PyObject*);

static inline _PyTypedMethodDef*
PyMethodDescr_GetTypedMethodDef(PyMethodDescrObject* method)
{
  assert(method->d_method->ml_flags & _METH_TYPED);
  return (_PyTypedMethodDef *)method->d_method->ml_meth;
}

static inline PyCFunction 
PyMethodDescr_GetTypedCFunction(PyMethodDescrObject* method)
{
  return PyMethodDescr_GetTypedMethodDef(method)->tmd_meth;
}

static inline _PyTypedMethodDef*
PyCFunction_GetTypedMethodDef(PyCFunctionObject* func)
{
  assert(func->m_ml->ml_flags & _METH_TYPED);
  return (_PyTypedMethodDef *)func->m_ml->ml_meth;
}

static inline PyCFunction 
PyCFunction_GetTypedCFunction(PyCFunctionObject* func)
{
  return PyCFunction_GetTypedMethodDef(func)->tmd_meth;
}

#ifdef __cplusplus
}
#endif
#endif   /* !Py_INTERNAL_TYPEDMETHODDEF_H */
