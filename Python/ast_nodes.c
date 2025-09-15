
#include <Python.h>

#include "pycore_ast.h"           // asdl_seq *

static void mod_dealloc(PyObject *self) {
    mod_ty obj = (mod_ty)self;
#ifdef REF_CNT_AST
    switch (obj->kind) {
        case Module_kind:
            break;
        case Interactive_kind:
            break;
        case Expression_kind:
            Py_XDECREF(obj->v.Expression.body);
            break;
        case FunctionType_kind:
            Py_XDECREF(obj->v.FunctionType.returns);
            break;
    }
#endif
    Py_TYPE(self)->tp_free(self);
}

PyTypeObject PyAst_mod_Type = {
    PyVarObject_HEAD_INIT(&PyType_Type, 0)
    "mod",                                   /* tp_name */
    sizeof(struct _mod),                     /* tp_basicsize */
    0,                                          /* tp_itemsize */
    mod_dealloc,                                          /* tp_dealloc */
    0,                                          /* tp_vectorcall_offset */
    0,                                          /* tp_getattr */
    0,                                          /* tp_setattr */
    0,                                          /* tp_as_async */
    0,                                          /* tp_repr */
    0,                                          /* tp_as_number */
    0,                                          /* tp_as_sequence */
    0,                                          /* tp_as_mapping */
    0,                                          /* tp_hash */
    0,                                          /* tp_call */
    0,                                          /* tp_str */
    PyObject_GenericGetAttr,                    /* tp_getattro */
    0,                                          /* tp_setattro */
    0,                                          /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,   /* tp_flags */
    "",                                         /* tp_doc */
    0,                                          /* tp_traverse */
    0,                                          /* tp_clear */
    0,                                          /* tp_richcompare */
    0,                                          /* tp_weaklistoffset */
    0,                                          /* tp_iter */
    0,                                          /* tp_iternext */
    0,                                          /* tp_methods */
    0,                                          /* tp_members */
    0,                                          /* tp_getset */
    0,                                          /* tp_base */
    0,                                          /* tp_dict */
    0,                                          /* tp_descr_get */
    0,                                          /* tp_descr_set */
    0,                                          /* tp_dictoffset */
    0,                                          /* tp_init */
    0,                                          /* tp_alloc */
    0,                                          /* tp_new */
    PyObject_Free,                              /* tp_free */
};

static void stmt_dealloc(PyObject *self) {
    stmt_ty obj = (stmt_ty)self;
#ifdef REF_CNT_AST
    switch (obj->kind) {
        case FunctionDef_kind:
            Py_XDECREF(obj->v.FunctionDef.name);
            Py_XDECREF(obj->v.FunctionDef.args);
            Py_XDECREF(obj->v.FunctionDef.returns);
            break;
        case AsyncFunctionDef_kind:
            Py_XDECREF(obj->v.AsyncFunctionDef.name);
            Py_XDECREF(obj->v.AsyncFunctionDef.args);
            Py_XDECREF(obj->v.AsyncFunctionDef.returns);
            break;
        case ClassDef_kind:
            Py_XDECREF(obj->v.ClassDef.name);
            break;
        case Return_kind:
            Py_XDECREF(obj->v.Return.value);
            break;
        case Delete_kind:
            break;
        case Assign_kind:
            Py_XDECREF(obj->v.Assign.value);
            break;
        case TypeAlias_kind:
            Py_XDECREF(obj->v.TypeAlias.name);
            Py_XDECREF(obj->v.TypeAlias.value);
            break;
        case AugAssign_kind:
            Py_XDECREF(obj->v.AugAssign.target);
            Py_XDECREF(obj->v.AugAssign.op);
            Py_XDECREF(obj->v.AugAssign.value);
            break;
        case AnnAssign_kind:
            Py_XDECREF(obj->v.AnnAssign.target);
            Py_XDECREF(obj->v.AnnAssign.annotation);
            Py_XDECREF(obj->v.AnnAssign.value);
            break;
        case For_kind:
            Py_XDECREF(obj->v.For.target);
            Py_XDECREF(obj->v.For.iter);
            break;
        case AsyncFor_kind:
            Py_XDECREF(obj->v.AsyncFor.target);
            Py_XDECREF(obj->v.AsyncFor.iter);
            break;
        case While_kind:
            Py_XDECREF(obj->v.While.test);
            break;
        case If_kind:
            Py_XDECREF(obj->v.If.test);
            break;
        case With_kind:
            break;
        case AsyncWith_kind:
            break;
        case Match_kind:
            Py_XDECREF(obj->v.Match.subject);
            break;
        case Raise_kind:
            Py_XDECREF(obj->v.Raise.exc);
            Py_XDECREF(obj->v.Raise.cause);
            break;
        case Try_kind:
            break;
        case TryStar_kind:
            break;
        case Assert_kind:
            Py_XDECREF(obj->v.Assert.test);
            Py_XDECREF(obj->v.Assert.msg);
            break;
        case Import_kind:
            break;
        case ImportFrom_kind:
            Py_XDECREF(obj->v.ImportFrom.module);
            break;
        case Global_kind:
            break;
        case Nonlocal_kind:
            break;
        case Expr_kind:
            Py_XDECREF(obj->v.Expr.value);
            break;
        case Pass_kind:
            break;
        case Break_kind:
            break;
        case Continue_kind:
            break;
    }
#endif
    Py_TYPE(self)->tp_free(self);
}

PyTypeObject PyAst_stmt_Type = {
    PyVarObject_HEAD_INIT(&PyType_Type, 0)
    "stmt",                                   /* tp_name */
    sizeof(struct _stmt),                     /* tp_basicsize */
    0,                                          /* tp_itemsize */
    stmt_dealloc,                                          /* tp_dealloc */
    0,                                          /* tp_vectorcall_offset */
    0,                                          /* tp_getattr */
    0,                                          /* tp_setattr */
    0,                                          /* tp_as_async */
    0,                                          /* tp_repr */
    0,                                          /* tp_as_number */
    0,                                          /* tp_as_sequence */
    0,                                          /* tp_as_mapping */
    0,                                          /* tp_hash */
    0,                                          /* tp_call */
    0,                                          /* tp_str */
    PyObject_GenericGetAttr,                    /* tp_getattro */
    0,                                          /* tp_setattro */
    0,                                          /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,   /* tp_flags */
    "",                                         /* tp_doc */
    0,                                          /* tp_traverse */
    0,                                          /* tp_clear */
    0,                                          /* tp_richcompare */
    0,                                          /* tp_weaklistoffset */
    0,                                          /* tp_iter */
    0,                                          /* tp_iternext */
    0,                                          /* tp_methods */
    0,                                          /* tp_members */
    0,                                          /* tp_getset */
    0,                                          /* tp_base */
    0,                                          /* tp_dict */
    0,                                          /* tp_descr_get */
    0,                                          /* tp_descr_set */
    0,                                          /* tp_dictoffset */
    0,                                          /* tp_init */
    0,                                          /* tp_alloc */
    0,                                          /* tp_new */
    PyObject_Free,                              /* tp_free */
};

static void expr_dealloc(PyObject *self) {
    expr_ty obj = (expr_ty)self;
#ifdef REF_CNT_AST
    switch (obj->kind) {
        case BoolOp_kind:
            Py_XDECREF(obj->v.BoolOp.op);
            break;
        case NamedExpr_kind:
            Py_XDECREF(obj->v.NamedExpr.target);
            Py_XDECREF(obj->v.NamedExpr.value);
            break;
        case BinOp_kind:
            Py_XDECREF(obj->v.BinOp.left);
            Py_XDECREF(obj->v.BinOp.op);
            Py_XDECREF(obj->v.BinOp.right);
            break;
        case UnaryOp_kind:
            Py_XDECREF(obj->v.UnaryOp.op);
            Py_XDECREF(obj->v.UnaryOp.operand);
            break;
        case Lambda_kind:
            Py_XDECREF(obj->v.Lambda.args);
            Py_XDECREF(obj->v.Lambda.body);
            break;
        case IfExp_kind:
            Py_XDECREF(obj->v.IfExp.test);
            Py_XDECREF(obj->v.IfExp.body);
            Py_XDECREF(obj->v.IfExp.orelse);
            break;
        case Dict_kind:
            break;
        case Set_kind:
            break;
        case ListComp_kind:
            Py_XDECREF(obj->v.ListComp.elt);
            break;
        case SetComp_kind:
            Py_XDECREF(obj->v.SetComp.elt);
            break;
        case DictComp_kind:
            Py_XDECREF(obj->v.DictComp.key);
            Py_XDECREF(obj->v.DictComp.value);
            break;
        case GeneratorExp_kind:
            Py_XDECREF(obj->v.GeneratorExp.elt);
            break;
        case Await_kind:
            Py_XDECREF(obj->v.Await.value);
            break;
        case Yield_kind:
            Py_XDECREF(obj->v.Yield.value);
            break;
        case YieldFrom_kind:
            Py_XDECREF(obj->v.YieldFrom.value);
            break;
        case Compare_kind:
            Py_XDECREF(obj->v.Compare.left);
            break;
        case Call_kind:
            Py_XDECREF(obj->v.Call.func);
            break;
        case FormattedValue_kind:
            Py_XDECREF(obj->v.FormattedValue.value);
            Py_XDECREF(obj->v.FormattedValue.format_spec);
            break;
        case Interpolation_kind:
            Py_XDECREF(obj->v.Interpolation.value);
            Py_XDECREF(obj->v.Interpolation.str);
            Py_XDECREF(obj->v.Interpolation.format_spec);
            break;
        case JoinedStr_kind:
            break;
        case TemplateStr_kind:
            break;
        case Constant_kind:
            Py_XDECREF(obj->v.Constant.value);
            break;
        case Attribute_kind:
            Py_XDECREF(obj->v.Attribute.value);
            Py_XDECREF(obj->v.Attribute.attr);
            Py_XDECREF(obj->v.Attribute.ctx);
            break;
        case Subscript_kind:
            Py_XDECREF(obj->v.Subscript.value);
            Py_XDECREF(obj->v.Subscript.slice);
            Py_XDECREF(obj->v.Subscript.ctx);
            break;
        case Starred_kind:
            Py_XDECREF(obj->v.Starred.value);
            Py_XDECREF(obj->v.Starred.ctx);
            break;
        case Name_kind:
            Py_XDECREF(obj->v.Name.id);
            Py_XDECREF(obj->v.Name.ctx);
            break;
        case List_kind:
            Py_XDECREF(obj->v.List.ctx);
            break;
        case Tuple_kind:
            Py_XDECREF(obj->v.Tuple.ctx);
            break;
        case Slice_kind:
            Py_XDECREF(obj->v.Slice.lower);
            Py_XDECREF(obj->v.Slice.upper);
            Py_XDECREF(obj->v.Slice.step);
            break;
    }
#endif
    Py_TYPE(self)->tp_free(self);
}

PyTypeObject PyAst_expr_Type = {
    PyVarObject_HEAD_INIT(&PyType_Type, 0)
    "expr",                                   /* tp_name */
    sizeof(struct _expr),                     /* tp_basicsize */
    0,                                          /* tp_itemsize */
    expr_dealloc,                                          /* tp_dealloc */
    0,                                          /* tp_vectorcall_offset */
    0,                                          /* tp_getattr */
    0,                                          /* tp_setattr */
    0,                                          /* tp_as_async */
    0,                                          /* tp_repr */
    0,                                          /* tp_as_number */
    0,                                          /* tp_as_sequence */
    0,                                          /* tp_as_mapping */
    0,                                          /* tp_hash */
    0,                                          /* tp_call */
    0,                                          /* tp_str */
    PyObject_GenericGetAttr,                    /* tp_getattro */
    0,                                          /* tp_setattro */
    0,                                          /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,   /* tp_flags */
    "",                                         /* tp_doc */
    0,                                          /* tp_traverse */
    0,                                          /* tp_clear */
    0,                                          /* tp_richcompare */
    0,                                          /* tp_weaklistoffset */
    0,                                          /* tp_iter */
    0,                                          /* tp_iternext */
    0,                                          /* tp_methods */
    0,                                          /* tp_members */
    0,                                          /* tp_getset */
    0,                                          /* tp_base */
    0,                                          /* tp_dict */
    0,                                          /* tp_descr_get */
    0,                                          /* tp_descr_set */
    0,                                          /* tp_dictoffset */
    0,                                          /* tp_init */
    0,                                          /* tp_alloc */
    0,                                          /* tp_new */
    PyObject_Free,                              /* tp_free */
};

static void comprehension_dealloc(PyObject *self) {
    comprehension_ty obj = (comprehension_ty)self;
#ifdef REF_CNT_AST
    Py_XDECREF(obj->target);
    Py_XDECREF(obj->iter);
#endif
    Py_TYPE(self)->tp_free(self);
}

PyTypeObject PyAst_comprehension_Type = {
    PyVarObject_HEAD_INIT(&PyType_Type, 0)
    "comprehension",                                   /* tp_name */
    sizeof(struct _comprehension),                     /* tp_basicsize */
    0,                                          /* tp_itemsize */
    comprehension_dealloc,                                          /* tp_dealloc */
    0,                                          /* tp_vectorcall_offset */
    0,                                          /* tp_getattr */
    0,                                          /* tp_setattr */
    0,                                          /* tp_as_async */
    0,                                          /* tp_repr */
    0,                                          /* tp_as_number */
    0,                                          /* tp_as_sequence */
    0,                                          /* tp_as_mapping */
    0,                                          /* tp_hash */
    0,                                          /* tp_call */
    0,                                          /* tp_str */
    PyObject_GenericGetAttr,                    /* tp_getattro */
    0,                                          /* tp_setattro */
    0,                                          /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,   /* tp_flags */
    "",                                         /* tp_doc */
    0,                                          /* tp_traverse */
    0,                                          /* tp_clear */
    0,                                          /* tp_richcompare */
    0,                                          /* tp_weaklistoffset */
    0,                                          /* tp_iter */
    0,                                          /* tp_iternext */
    0,                                          /* tp_methods */
    0,                                          /* tp_members */
    0,                                          /* tp_getset */
    0,                                          /* tp_base */
    0,                                          /* tp_dict */
    0,                                          /* tp_descr_get */
    0,                                          /* tp_descr_set */
    0,                                          /* tp_dictoffset */
    0,                                          /* tp_init */
    0,                                          /* tp_alloc */
    0,                                          /* tp_new */
    PyObject_Free,                              /* tp_free */
};

static void excepthandler_dealloc(PyObject *self) {
    excepthandler_ty obj = (excepthandler_ty)self;
#ifdef REF_CNT_AST
    switch (obj->kind) {
        case ExceptHandler_kind:
            Py_XDECREF(obj->v.ExceptHandler.type);
            Py_XDECREF(obj->v.ExceptHandler.name);
            break;
    }
#endif
    Py_TYPE(self)->tp_free(self);
}

PyTypeObject PyAst_excepthandler_Type = {
    PyVarObject_HEAD_INIT(&PyType_Type, 0)
    "excepthandler",                                   /* tp_name */
    sizeof(struct _excepthandler),                     /* tp_basicsize */
    0,                                          /* tp_itemsize */
    excepthandler_dealloc,                                          /* tp_dealloc */
    0,                                          /* tp_vectorcall_offset */
    0,                                          /* tp_getattr */
    0,                                          /* tp_setattr */
    0,                                          /* tp_as_async */
    0,                                          /* tp_repr */
    0,                                          /* tp_as_number */
    0,                                          /* tp_as_sequence */
    0,                                          /* tp_as_mapping */
    0,                                          /* tp_hash */
    0,                                          /* tp_call */
    0,                                          /* tp_str */
    PyObject_GenericGetAttr,                    /* tp_getattro */
    0,                                          /* tp_setattro */
    0,                                          /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,   /* tp_flags */
    "",                                         /* tp_doc */
    0,                                          /* tp_traverse */
    0,                                          /* tp_clear */
    0,                                          /* tp_richcompare */
    0,                                          /* tp_weaklistoffset */
    0,                                          /* tp_iter */
    0,                                          /* tp_iternext */
    0,                                          /* tp_methods */
    0,                                          /* tp_members */
    0,                                          /* tp_getset */
    0,                                          /* tp_base */
    0,                                          /* tp_dict */
    0,                                          /* tp_descr_get */
    0,                                          /* tp_descr_set */
    0,                                          /* tp_dictoffset */
    0,                                          /* tp_init */
    0,                                          /* tp_alloc */
    0,                                          /* tp_new */
    PyObject_Free,                              /* tp_free */
};

static void arguments_dealloc(PyObject *self) {
    arguments_ty obj = (arguments_ty)self;
#ifdef REF_CNT_AST
    Py_XDECREF(obj->vararg);
    Py_XDECREF(obj->kwarg);
#endif
    Py_TYPE(self)->tp_free(self);
}

PyTypeObject PyAst_arguments_Type = {
    PyVarObject_HEAD_INIT(&PyType_Type, 0)
    "arguments",                                   /* tp_name */
    sizeof(struct _arguments),                     /* tp_basicsize */
    0,                                          /* tp_itemsize */
    arguments_dealloc,                                          /* tp_dealloc */
    0,                                          /* tp_vectorcall_offset */
    0,                                          /* tp_getattr */
    0,                                          /* tp_setattr */
    0,                                          /* tp_as_async */
    0,                                          /* tp_repr */
    0,                                          /* tp_as_number */
    0,                                          /* tp_as_sequence */
    0,                                          /* tp_as_mapping */
    0,                                          /* tp_hash */
    0,                                          /* tp_call */
    0,                                          /* tp_str */
    PyObject_GenericGetAttr,                    /* tp_getattro */
    0,                                          /* tp_setattro */
    0,                                          /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,   /* tp_flags */
    "",                                         /* tp_doc */
    0,                                          /* tp_traverse */
    0,                                          /* tp_clear */
    0,                                          /* tp_richcompare */
    0,                                          /* tp_weaklistoffset */
    0,                                          /* tp_iter */
    0,                                          /* tp_iternext */
    0,                                          /* tp_methods */
    0,                                          /* tp_members */
    0,                                          /* tp_getset */
    0,                                          /* tp_base */
    0,                                          /* tp_dict */
    0,                                          /* tp_descr_get */
    0,                                          /* tp_descr_set */
    0,                                          /* tp_dictoffset */
    0,                                          /* tp_init */
    0,                                          /* tp_alloc */
    0,                                          /* tp_new */
    PyObject_Free,                              /* tp_free */
};

static void arg_dealloc(PyObject *self) {
    arg_ty obj = (arg_ty)self;
#ifdef REF_CNT_AST
    Py_XDECREF(obj->arg);
    Py_XDECREF(obj->annotation);
#endif
    Py_TYPE(self)->tp_free(self);
}

PyTypeObject PyAst_arg_Type = {
    PyVarObject_HEAD_INIT(&PyType_Type, 0)
    "arg",                                   /* tp_name */
    sizeof(struct _arg),                     /* tp_basicsize */
    0,                                          /* tp_itemsize */
    arg_dealloc,                                          /* tp_dealloc */
    0,                                          /* tp_vectorcall_offset */
    0,                                          /* tp_getattr */
    0,                                          /* tp_setattr */
    0,                                          /* tp_as_async */
    0,                                          /* tp_repr */
    0,                                          /* tp_as_number */
    0,                                          /* tp_as_sequence */
    0,                                          /* tp_as_mapping */
    0,                                          /* tp_hash */
    0,                                          /* tp_call */
    0,                                          /* tp_str */
    PyObject_GenericGetAttr,                    /* tp_getattro */
    0,                                          /* tp_setattro */
    0,                                          /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,   /* tp_flags */
    "",                                         /* tp_doc */
    0,                                          /* tp_traverse */
    0,                                          /* tp_clear */
    0,                                          /* tp_richcompare */
    0,                                          /* tp_weaklistoffset */
    0,                                          /* tp_iter */
    0,                                          /* tp_iternext */
    0,                                          /* tp_methods */
    0,                                          /* tp_members */
    0,                                          /* tp_getset */
    0,                                          /* tp_base */
    0,                                          /* tp_dict */
    0,                                          /* tp_descr_get */
    0,                                          /* tp_descr_set */
    0,                                          /* tp_dictoffset */
    0,                                          /* tp_init */
    0,                                          /* tp_alloc */
    0,                                          /* tp_new */
    PyObject_Free,                              /* tp_free */
};

static void keyword_dealloc(PyObject *self) {
    keyword_ty obj = (keyword_ty)self;
#ifdef REF_CNT_AST
    Py_XDECREF(obj->arg);
    Py_XDECREF(obj->value);
#endif
    Py_TYPE(self)->tp_free(self);
}

PyTypeObject PyAst_keyword_Type = {
    PyVarObject_HEAD_INIT(&PyType_Type, 0)
    "keyword",                                   /* tp_name */
    sizeof(struct _keyword),                     /* tp_basicsize */
    0,                                          /* tp_itemsize */
    keyword_dealloc,                                          /* tp_dealloc */
    0,                                          /* tp_vectorcall_offset */
    0,                                          /* tp_getattr */
    0,                                          /* tp_setattr */
    0,                                          /* tp_as_async */
    0,                                          /* tp_repr */
    0,                                          /* tp_as_number */
    0,                                          /* tp_as_sequence */
    0,                                          /* tp_as_mapping */
    0,                                          /* tp_hash */
    0,                                          /* tp_call */
    0,                                          /* tp_str */
    PyObject_GenericGetAttr,                    /* tp_getattro */
    0,                                          /* tp_setattro */
    0,                                          /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,   /* tp_flags */
    "",                                         /* tp_doc */
    0,                                          /* tp_traverse */
    0,                                          /* tp_clear */
    0,                                          /* tp_richcompare */
    0,                                          /* tp_weaklistoffset */
    0,                                          /* tp_iter */
    0,                                          /* tp_iternext */
    0,                                          /* tp_methods */
    0,                                          /* tp_members */
    0,                                          /* tp_getset */
    0,                                          /* tp_base */
    0,                                          /* tp_dict */
    0,                                          /* tp_descr_get */
    0,                                          /* tp_descr_set */
    0,                                          /* tp_dictoffset */
    0,                                          /* tp_init */
    0,                                          /* tp_alloc */
    0,                                          /* tp_new */
    PyObject_Free,                              /* tp_free */
};

static void alias_dealloc(PyObject *self) {
    alias_ty obj = (alias_ty)self;
#ifdef REF_CNT_AST
    Py_XDECREF(obj->name);
    Py_XDECREF(obj->asname);
#endif
    Py_TYPE(self)->tp_free(self);
}

PyTypeObject PyAst_alias_Type = {
    PyVarObject_HEAD_INIT(&PyType_Type, 0)
    "alias",                                   /* tp_name */
    sizeof(struct _alias),                     /* tp_basicsize */
    0,                                          /* tp_itemsize */
    alias_dealloc,                                          /* tp_dealloc */
    0,                                          /* tp_vectorcall_offset */
    0,                                          /* tp_getattr */
    0,                                          /* tp_setattr */
    0,                                          /* tp_as_async */
    0,                                          /* tp_repr */
    0,                                          /* tp_as_number */
    0,                                          /* tp_as_sequence */
    0,                                          /* tp_as_mapping */
    0,                                          /* tp_hash */
    0,                                          /* tp_call */
    0,                                          /* tp_str */
    PyObject_GenericGetAttr,                    /* tp_getattro */
    0,                                          /* tp_setattro */
    0,                                          /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,   /* tp_flags */
    "",                                         /* tp_doc */
    0,                                          /* tp_traverse */
    0,                                          /* tp_clear */
    0,                                          /* tp_richcompare */
    0,                                          /* tp_weaklistoffset */
    0,                                          /* tp_iter */
    0,                                          /* tp_iternext */
    0,                                          /* tp_methods */
    0,                                          /* tp_members */
    0,                                          /* tp_getset */
    0,                                          /* tp_base */
    0,                                          /* tp_dict */
    0,                                          /* tp_descr_get */
    0,                                          /* tp_descr_set */
    0,                                          /* tp_dictoffset */
    0,                                          /* tp_init */
    0,                                          /* tp_alloc */
    0,                                          /* tp_new */
    PyObject_Free,                              /* tp_free */
};

static void withitem_dealloc(PyObject *self) {
    withitem_ty obj = (withitem_ty)self;
#ifdef REF_CNT_AST
    Py_XDECREF(obj->context_expr);
    Py_XDECREF(obj->optional_vars);
#endif
    Py_TYPE(self)->tp_free(self);
}

PyTypeObject PyAst_withitem_Type = {
    PyVarObject_HEAD_INIT(&PyType_Type, 0)
    "withitem",                                   /* tp_name */
    sizeof(struct _withitem),                     /* tp_basicsize */
    0,                                          /* tp_itemsize */
    withitem_dealloc,                                          /* tp_dealloc */
    0,                                          /* tp_vectorcall_offset */
    0,                                          /* tp_getattr */
    0,                                          /* tp_setattr */
    0,                                          /* tp_as_async */
    0,                                          /* tp_repr */
    0,                                          /* tp_as_number */
    0,                                          /* tp_as_sequence */
    0,                                          /* tp_as_mapping */
    0,                                          /* tp_hash */
    0,                                          /* tp_call */
    0,                                          /* tp_str */
    PyObject_GenericGetAttr,                    /* tp_getattro */
    0,                                          /* tp_setattro */
    0,                                          /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,   /* tp_flags */
    "",                                         /* tp_doc */
    0,                                          /* tp_traverse */
    0,                                          /* tp_clear */
    0,                                          /* tp_richcompare */
    0,                                          /* tp_weaklistoffset */
    0,                                          /* tp_iter */
    0,                                          /* tp_iternext */
    0,                                          /* tp_methods */
    0,                                          /* tp_members */
    0,                                          /* tp_getset */
    0,                                          /* tp_base */
    0,                                          /* tp_dict */
    0,                                          /* tp_descr_get */
    0,                                          /* tp_descr_set */
    0,                                          /* tp_dictoffset */
    0,                                          /* tp_init */
    0,                                          /* tp_alloc */
    0,                                          /* tp_new */
    PyObject_Free,                              /* tp_free */
};

static void match_case_dealloc(PyObject *self) {
    match_case_ty obj = (match_case_ty)self;
#ifdef REF_CNT_AST
    Py_XDECREF(obj->pattern);
    Py_XDECREF(obj->guard);
#endif
    Py_TYPE(self)->tp_free(self);
}

PyTypeObject PyAst_match_case_Type = {
    PyVarObject_HEAD_INIT(&PyType_Type, 0)
    "match_case",                                   /* tp_name */
    sizeof(struct _match_case),                     /* tp_basicsize */
    0,                                          /* tp_itemsize */
    match_case_dealloc,                                          /* tp_dealloc */
    0,                                          /* tp_vectorcall_offset */
    0,                                          /* tp_getattr */
    0,                                          /* tp_setattr */
    0,                                          /* tp_as_async */
    0,                                          /* tp_repr */
    0,                                          /* tp_as_number */
    0,                                          /* tp_as_sequence */
    0,                                          /* tp_as_mapping */
    0,                                          /* tp_hash */
    0,                                          /* tp_call */
    0,                                          /* tp_str */
    PyObject_GenericGetAttr,                    /* tp_getattro */
    0,                                          /* tp_setattro */
    0,                                          /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,   /* tp_flags */
    "",                                         /* tp_doc */
    0,                                          /* tp_traverse */
    0,                                          /* tp_clear */
    0,                                          /* tp_richcompare */
    0,                                          /* tp_weaklistoffset */
    0,                                          /* tp_iter */
    0,                                          /* tp_iternext */
    0,                                          /* tp_methods */
    0,                                          /* tp_members */
    0,                                          /* tp_getset */
    0,                                          /* tp_base */
    0,                                          /* tp_dict */
    0,                                          /* tp_descr_get */
    0,                                          /* tp_descr_set */
    0,                                          /* tp_dictoffset */
    0,                                          /* tp_init */
    0,                                          /* tp_alloc */
    0,                                          /* tp_new */
    PyObject_Free,                              /* tp_free */
};

static void pattern_dealloc(PyObject *self) {
    pattern_ty obj = (pattern_ty)self;
#ifdef REF_CNT_AST
    switch (obj->kind) {
        case MatchValue_kind:
            Py_XDECREF(obj->v.MatchValue.value);
            break;
        case MatchSingleton_kind:
            Py_XDECREF(obj->v.MatchSingleton.value);
            break;
        case MatchSequence_kind:
            break;
        case MatchMapping_kind:
            Py_XDECREF(obj->v.MatchMapping.rest);
            break;
        case MatchClass_kind:
            Py_XDECREF(obj->v.MatchClass.cls);
            break;
        case MatchStar_kind:
            Py_XDECREF(obj->v.MatchStar.name);
            break;
        case MatchAs_kind:
            Py_XDECREF(obj->v.MatchAs.pattern);
            Py_XDECREF(obj->v.MatchAs.name);
            break;
        case MatchOr_kind:
            break;
    }
#endif
    Py_TYPE(self)->tp_free(self);
}

PyTypeObject PyAst_pattern_Type = {
    PyVarObject_HEAD_INIT(&PyType_Type, 0)
    "pattern",                                   /* tp_name */
    sizeof(struct _pattern),                     /* tp_basicsize */
    0,                                          /* tp_itemsize */
    pattern_dealloc,                                          /* tp_dealloc */
    0,                                          /* tp_vectorcall_offset */
    0,                                          /* tp_getattr */
    0,                                          /* tp_setattr */
    0,                                          /* tp_as_async */
    0,                                          /* tp_repr */
    0,                                          /* tp_as_number */
    0,                                          /* tp_as_sequence */
    0,                                          /* tp_as_mapping */
    0,                                          /* tp_hash */
    0,                                          /* tp_call */
    0,                                          /* tp_str */
    PyObject_GenericGetAttr,                    /* tp_getattro */
    0,                                          /* tp_setattro */
    0,                                          /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,   /* tp_flags */
    "",                                         /* tp_doc */
    0,                                          /* tp_traverse */
    0,                                          /* tp_clear */
    0,                                          /* tp_richcompare */
    0,                                          /* tp_weaklistoffset */
    0,                                          /* tp_iter */
    0,                                          /* tp_iternext */
    0,                                          /* tp_methods */
    0,                                          /* tp_members */
    0,                                          /* tp_getset */
    0,                                          /* tp_base */
    0,                                          /* tp_dict */
    0,                                          /* tp_descr_get */
    0,                                          /* tp_descr_set */
    0,                                          /* tp_dictoffset */
    0,                                          /* tp_init */
    0,                                          /* tp_alloc */
    0,                                          /* tp_new */
    PyObject_Free,                              /* tp_free */
};

static void type_ignore_dealloc(PyObject *self) {
    type_ignore_ty obj = (type_ignore_ty)self;
#ifdef REF_CNT_AST
    switch (obj->kind) {
        case TypeIgnore_kind:
            break;
    }
#endif
    Py_TYPE(self)->tp_free(self);
}

PyTypeObject PyAst_type_ignore_Type = {
    PyVarObject_HEAD_INIT(&PyType_Type, 0)
    "type_ignore",                                   /* tp_name */
    sizeof(struct _type_ignore),                     /* tp_basicsize */
    0,                                          /* tp_itemsize */
    type_ignore_dealloc,                                          /* tp_dealloc */
    0,                                          /* tp_vectorcall_offset */
    0,                                          /* tp_getattr */
    0,                                          /* tp_setattr */
    0,                                          /* tp_as_async */
    0,                                          /* tp_repr */
    0,                                          /* tp_as_number */
    0,                                          /* tp_as_sequence */
    0,                                          /* tp_as_mapping */
    0,                                          /* tp_hash */
    0,                                          /* tp_call */
    0,                                          /* tp_str */
    PyObject_GenericGetAttr,                    /* tp_getattro */
    0,                                          /* tp_setattro */
    0,                                          /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,   /* tp_flags */
    "",                                         /* tp_doc */
    0,                                          /* tp_traverse */
    0,                                          /* tp_clear */
    0,                                          /* tp_richcompare */
    0,                                          /* tp_weaklistoffset */
    0,                                          /* tp_iter */
    0,                                          /* tp_iternext */
    0,                                          /* tp_methods */
    0,                                          /* tp_members */
    0,                                          /* tp_getset */
    0,                                          /* tp_base */
    0,                                          /* tp_dict */
    0,                                          /* tp_descr_get */
    0,                                          /* tp_descr_set */
    0,                                          /* tp_dictoffset */
    0,                                          /* tp_init */
    0,                                          /* tp_alloc */
    0,                                          /* tp_new */
    PyObject_Free,                              /* tp_free */
};

static void type_param_dealloc(PyObject *self) {
    type_param_ty obj = (type_param_ty)self;
#ifdef REF_CNT_AST
    switch (obj->kind) {
        case TypeVar_kind:
            Py_XDECREF(obj->v.TypeVar.name);
            Py_XDECREF(obj->v.TypeVar.bound);
            Py_XDECREF(obj->v.TypeVar.default_value);
            break;
        case ParamSpec_kind:
            Py_XDECREF(obj->v.ParamSpec.name);
            Py_XDECREF(obj->v.ParamSpec.default_value);
            break;
        case TypeVarTuple_kind:
            Py_XDECREF(obj->v.TypeVarTuple.name);
            Py_XDECREF(obj->v.TypeVarTuple.default_value);
            break;
    }
#endif
    Py_TYPE(self)->tp_free(self);
}

PyTypeObject PyAst_type_param_Type = {
    PyVarObject_HEAD_INIT(&PyType_Type, 0)
    "type_param",                                   /* tp_name */
    sizeof(struct _type_param),                     /* tp_basicsize */
    0,                                          /* tp_itemsize */
    type_param_dealloc,                                          /* tp_dealloc */
    0,                                          /* tp_vectorcall_offset */
    0,                                          /* tp_getattr */
    0,                                          /* tp_setattr */
    0,                                          /* tp_as_async */
    0,                                          /* tp_repr */
    0,                                          /* tp_as_number */
    0,                                          /* tp_as_sequence */
    0,                                          /* tp_as_mapping */
    0,                                          /* tp_hash */
    0,                                          /* tp_call */
    0,                                          /* tp_str */
    PyObject_GenericGetAttr,                    /* tp_getattro */
    0,                                          /* tp_setattro */
    0,                                          /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,   /* tp_flags */
    "",                                         /* tp_doc */
    0,                                          /* tp_traverse */
    0,                                          /* tp_clear */
    0,                                          /* tp_richcompare */
    0,                                          /* tp_weaklistoffset */
    0,                                          /* tp_iter */
    0,                                          /* tp_iternext */
    0,                                          /* tp_methods */
    0,                                          /* tp_members */
    0,                                          /* tp_getset */
    0,                                          /* tp_base */
    0,                                          /* tp_dict */
    0,                                          /* tp_descr_get */
    0,                                          /* tp_descr_set */
    0,                                          /* tp_dictoffset */
    0,                                          /* tp_init */
    0,                                          /* tp_alloc */
    0,                                          /* tp_new */
    PyObject_Free,                              /* tp_free */
};


