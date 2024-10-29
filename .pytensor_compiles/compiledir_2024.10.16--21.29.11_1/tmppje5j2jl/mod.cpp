#include <Python.h>
#include <iostream>
#include "pytensor_mod_helper.h"
#include <math.h>
#include <numpy/arrayobject.h>
#include <numpy/arrayscalars.h>
#include <vector>
#include <algorithm>
//////////////////////
////  Support Code
//////////////////////

    namespace {
    struct __struct_compiled_op_m158937ba65a097497b84a2324371ae53dfd7c158755888832b5ed5e7530f673a {
        PyObject* __ERROR;

        PyObject* storage_V11;
PyObject* storage_V9;
PyObject* storage_V7;
PyObject* storage_V5;
PyObject* storage_V3;
PyObject* storage_V1;
        

        __struct_compiled_op_m158937ba65a097497b84a2324371ae53dfd7c158755888832b5ed5e7530f673a() {
            // This is only somewhat safe because we:
            //  1) Are not a virtual class
            //  2) Do not use any virtual classes in the members
            //  3) Deal with mostly POD and pointers

            // If this changes, we would have to revise this, but for
            // now I am tired of chasing segfaults because
            // initialization code had an error and some pointer has
            // a junk value.
            #ifndef PYTENSOR_DONT_MEMSET_STRUCT
            memset(this, 0, sizeof(*this));
            #endif
        }
        ~__struct_compiled_op_m158937ba65a097497b84a2324371ae53dfd7c158755888832b5ed5e7530f673a(void) {
            cleanup();
        }

        int init(PyObject* __ERROR, PyObject* storage_V11, PyObject* storage_V9, PyObject* storage_V7, PyObject* storage_V5, PyObject* storage_V3, PyObject* storage_V1) {
            Py_XINCREF(storage_V11);
Py_XINCREF(storage_V9);
Py_XINCREF(storage_V7);
Py_XINCREF(storage_V5);
Py_XINCREF(storage_V3);
Py_XINCREF(storage_V1);
            this->storage_V11 = storage_V11;
this->storage_V9 = storage_V9;
this->storage_V7 = storage_V7;
this->storage_V5 = storage_V5;
this->storage_V3 = storage_V3;
this->storage_V1 = storage_V1;
            







            this->__ERROR = __ERROR;
            return 0;
        }
        void cleanup(void) {
            __label_1:

double __DUMMY_1;
__label_3:

double __DUMMY_3;
__label_5:

double __DUMMY_5;
__label_7:

double __DUMMY_7;
__label_9:

double __DUMMY_9;
__label_11:

double __DUMMY_11;
__label_14:

double __DUMMY_14;

            Py_XDECREF(this->storage_V11);
Py_XDECREF(this->storage_V9);
Py_XDECREF(this->storage_V7);
Py_XDECREF(this->storage_V5);
Py_XDECREF(this->storage_V3);
Py_XDECREF(this->storage_V1);
        }
        int run(void) {
            int __failure = 0;
            
    PyObject* py_V1;
    
        PyArrayObject* V1;
        
            typedef npy_float64 dtype_V1;
            
    PyObject* py_V3;
    
        PyArrayObject* V3;
        
            typedef npy_float64 dtype_V3;
            
    PyObject* py_V5;
    
        PyArrayObject* V5;
        
            typedef npy_float64 dtype_V5;
            
    PyObject* py_V7;
    
        PyArrayObject* V7;
        
            typedef npy_float64 dtype_V7;
            
    PyObject* py_V9;
    
        PyArrayObject* V9;
        
            typedef npy_float64 dtype_V9;
            
    PyObject* py_V11;
    
        PyArrayObject* V11;
        
            typedef npy_float64 dtype_V11;
            
{

    py_V1 = PyList_GET_ITEM(storage_V1, 0);
    {Py_XINCREF(py_V1);}
    
        if (py_V1 == Py_None)
        {
            
        V1 = NULL;
        
        }
        else
        {
            
            V1 = NULL;
            if (py_V1 == Py_None) {
                // We can either fail here or set V1 to NULL and rely on Ops
                // using tensors to handle the NULL case, but if they fail to do so
                // they'll end up with nasty segfaults, so this is public service.
                PyErr_SetString(PyExc_ValueError, "expected an ndarray, not None");
                {
        __failure = 2;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
        }
        goto __label_2;}
            }
            if (!PyArray_Check(py_V1)) {
                PyErr_SetString(PyExc_ValueError, "expected an ndarray");
                {
        __failure = 2;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
        }
        goto __label_2;}
            }
            // We expect NPY_FLOAT64
            if (!PyArray_ISALIGNED((PyArrayObject*) py_V1)) {
                PyArrayObject * tmp = (PyArrayObject*) py_V1;
                PyErr_Format(PyExc_NotImplementedError,
                             "expected an aligned array of type %ld "
                             "(NPY_FLOAT64), got non-aligned array of type %ld"
                             " with %ld dimensions, with 3 last dims "
                             "%ld, %ld, %ld"
                             " and 3 last strides %ld %ld, %ld.",
                             (long int) NPY_FLOAT64,
                             (long int) PyArray_TYPE((PyArrayObject*) py_V1),
                             (long int) PyArray_NDIM(tmp),
                             (long int) (PyArray_NDIM(tmp) >= 3 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-3] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 2 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-2] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 1 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-1] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 3 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-3] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 2 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-2] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 1 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-1] : -1)
            );
                {
        __failure = 2;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
        }
        goto __label_2;}
            }
            // This is a TypeError to be consistent with DEBUG_MODE
            // Note: DEBUG_MODE also tells the name of the container
            if (PyArray_TYPE((PyArrayObject*) py_V1) != NPY_FLOAT64) {
                PyErr_Format(PyExc_TypeError,
                             "expected type_num %d (NPY_FLOAT64) got %d",
                             NPY_FLOAT64, PyArray_TYPE((PyArrayObject*) py_V1));
                {
        __failure = 2;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
        }
        goto __label_2;}
            }
            
        V1 = (PyArrayObject*)(py_V1);
        Py_XINCREF(V1);
        
        }
        
{

    py_V3 = PyList_GET_ITEM(storage_V3, 0);
    {Py_XINCREF(py_V3);}
    
            V3 = NULL;
            if (py_V3 == Py_None) {
                // We can either fail here or set V3 to NULL and rely on Ops
                // using tensors to handle the NULL case, but if they fail to do so
                // they'll end up with nasty segfaults, so this is public service.
                PyErr_SetString(PyExc_ValueError, "expected an ndarray, not None");
                {
        __failure = 4;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
        }
        goto __label_4;}
            }
            if (!PyArray_Check(py_V3)) {
                PyErr_SetString(PyExc_ValueError, "expected an ndarray");
                {
        __failure = 4;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
        }
        goto __label_4;}
            }
            // We expect NPY_FLOAT64
            if (!PyArray_ISALIGNED((PyArrayObject*) py_V3)) {
                PyArrayObject * tmp = (PyArrayObject*) py_V3;
                PyErr_Format(PyExc_NotImplementedError,
                             "expected an aligned array of type %ld "
                             "(NPY_FLOAT64), got non-aligned array of type %ld"
                             " with %ld dimensions, with 3 last dims "
                             "%ld, %ld, %ld"
                             " and 3 last strides %ld %ld, %ld.",
                             (long int) NPY_FLOAT64,
                             (long int) PyArray_TYPE((PyArrayObject*) py_V3),
                             (long int) PyArray_NDIM(tmp),
                             (long int) (PyArray_NDIM(tmp) >= 3 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-3] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 2 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-2] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 1 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-1] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 3 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-3] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 2 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-2] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 1 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-1] : -1)
            );
                {
        __failure = 4;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
        }
        goto __label_4;}
            }
            // This is a TypeError to be consistent with DEBUG_MODE
            // Note: DEBUG_MODE also tells the name of the container
            if (PyArray_TYPE((PyArrayObject*) py_V3) != NPY_FLOAT64) {
                PyErr_Format(PyExc_TypeError,
                             "expected type_num %d (NPY_FLOAT64) got %d",
                             NPY_FLOAT64, PyArray_TYPE((PyArrayObject*) py_V3));
                {
        __failure = 4;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
        }
        goto __label_4;}
            }
            
        V3 = (PyArrayObject*)(py_V3);
        Py_XINCREF(V3);
        
{

    py_V5 = PyList_GET_ITEM(storage_V5, 0);
    {Py_XINCREF(py_V5);}
    
            V5 = NULL;
            if (py_V5 == Py_None) {
                // We can either fail here or set V5 to NULL and rely on Ops
                // using tensors to handle the NULL case, but if they fail to do so
                // they'll end up with nasty segfaults, so this is public service.
                PyErr_SetString(PyExc_ValueError, "expected an ndarray, not None");
                {
        __failure = 6;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
        }
        goto __label_6;}
            }
            if (!PyArray_Check(py_V5)) {
                PyErr_SetString(PyExc_ValueError, "expected an ndarray");
                {
        __failure = 6;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
        }
        goto __label_6;}
            }
            // We expect NPY_FLOAT64
            if (!PyArray_ISALIGNED((PyArrayObject*) py_V5)) {
                PyArrayObject * tmp = (PyArrayObject*) py_V5;
                PyErr_Format(PyExc_NotImplementedError,
                             "expected an aligned array of type %ld "
                             "(NPY_FLOAT64), got non-aligned array of type %ld"
                             " with %ld dimensions, with 3 last dims "
                             "%ld, %ld, %ld"
                             " and 3 last strides %ld %ld, %ld.",
                             (long int) NPY_FLOAT64,
                             (long int) PyArray_TYPE((PyArrayObject*) py_V5),
                             (long int) PyArray_NDIM(tmp),
                             (long int) (PyArray_NDIM(tmp) >= 3 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-3] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 2 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-2] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 1 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-1] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 3 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-3] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 2 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-2] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 1 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-1] : -1)
            );
                {
        __failure = 6;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
        }
        goto __label_6;}
            }
            // This is a TypeError to be consistent with DEBUG_MODE
            // Note: DEBUG_MODE also tells the name of the container
            if (PyArray_TYPE((PyArrayObject*) py_V5) != NPY_FLOAT64) {
                PyErr_Format(PyExc_TypeError,
                             "expected type_num %d (NPY_FLOAT64) got %d",
                             NPY_FLOAT64, PyArray_TYPE((PyArrayObject*) py_V5));
                {
        __failure = 6;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
        }
        goto __label_6;}
            }
            
        V5 = (PyArrayObject*)(py_V5);
        Py_XINCREF(V5);
        
{

    py_V7 = PyList_GET_ITEM(storage_V7, 0);
    {Py_XINCREF(py_V7);}
    
            V7 = NULL;
            if (py_V7 == Py_None) {
                // We can either fail here or set V7 to NULL and rely on Ops
                // using tensors to handle the NULL case, but if they fail to do so
                // they'll end up with nasty segfaults, so this is public service.
                PyErr_SetString(PyExc_ValueError, "expected an ndarray, not None");
                {
        __failure = 8;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
        }
        goto __label_8;}
            }
            if (!PyArray_Check(py_V7)) {
                PyErr_SetString(PyExc_ValueError, "expected an ndarray");
                {
        __failure = 8;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
        }
        goto __label_8;}
            }
            // We expect NPY_FLOAT64
            if (!PyArray_ISALIGNED((PyArrayObject*) py_V7)) {
                PyArrayObject * tmp = (PyArrayObject*) py_V7;
                PyErr_Format(PyExc_NotImplementedError,
                             "expected an aligned array of type %ld "
                             "(NPY_FLOAT64), got non-aligned array of type %ld"
                             " with %ld dimensions, with 3 last dims "
                             "%ld, %ld, %ld"
                             " and 3 last strides %ld %ld, %ld.",
                             (long int) NPY_FLOAT64,
                             (long int) PyArray_TYPE((PyArrayObject*) py_V7),
                             (long int) PyArray_NDIM(tmp),
                             (long int) (PyArray_NDIM(tmp) >= 3 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-3] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 2 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-2] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 1 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-1] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 3 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-3] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 2 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-2] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 1 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-1] : -1)
            );
                {
        __failure = 8;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
        }
        goto __label_8;}
            }
            // This is a TypeError to be consistent with DEBUG_MODE
            // Note: DEBUG_MODE also tells the name of the container
            if (PyArray_TYPE((PyArrayObject*) py_V7) != NPY_FLOAT64) {
                PyErr_Format(PyExc_TypeError,
                             "expected type_num %d (NPY_FLOAT64) got %d",
                             NPY_FLOAT64, PyArray_TYPE((PyArrayObject*) py_V7));
                {
        __failure = 8;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
        }
        goto __label_8;}
            }
            
        V7 = (PyArrayObject*)(py_V7);
        Py_XINCREF(V7);
        
{

    py_V9 = PyList_GET_ITEM(storage_V9, 0);
    {Py_XINCREF(py_V9);}
    
            V9 = NULL;
            if (py_V9 == Py_None) {
                // We can either fail here or set V9 to NULL and rely on Ops
                // using tensors to handle the NULL case, but if they fail to do so
                // they'll end up with nasty segfaults, so this is public service.
                PyErr_SetString(PyExc_ValueError, "expected an ndarray, not None");
                {
        __failure = 10;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
        }
        goto __label_10;}
            }
            if (!PyArray_Check(py_V9)) {
                PyErr_SetString(PyExc_ValueError, "expected an ndarray");
                {
        __failure = 10;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
        }
        goto __label_10;}
            }
            // We expect NPY_FLOAT64
            if (!PyArray_ISALIGNED((PyArrayObject*) py_V9)) {
                PyArrayObject * tmp = (PyArrayObject*) py_V9;
                PyErr_Format(PyExc_NotImplementedError,
                             "expected an aligned array of type %ld "
                             "(NPY_FLOAT64), got non-aligned array of type %ld"
                             " with %ld dimensions, with 3 last dims "
                             "%ld, %ld, %ld"
                             " and 3 last strides %ld %ld, %ld.",
                             (long int) NPY_FLOAT64,
                             (long int) PyArray_TYPE((PyArrayObject*) py_V9),
                             (long int) PyArray_NDIM(tmp),
                             (long int) (PyArray_NDIM(tmp) >= 3 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-3] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 2 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-2] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 1 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-1] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 3 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-3] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 2 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-2] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 1 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-1] : -1)
            );
                {
        __failure = 10;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
        }
        goto __label_10;}
            }
            // This is a TypeError to be consistent with DEBUG_MODE
            // Note: DEBUG_MODE also tells the name of the container
            if (PyArray_TYPE((PyArrayObject*) py_V9) != NPY_FLOAT64) {
                PyErr_Format(PyExc_TypeError,
                             "expected type_num %d (NPY_FLOAT64) got %d",
                             NPY_FLOAT64, PyArray_TYPE((PyArrayObject*) py_V9));
                {
        __failure = 10;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
        }
        goto __label_10;}
            }
            
        V9 = (PyArrayObject*)(py_V9);
        Py_XINCREF(V9);
        
{

    py_V11 = PyList_GET_ITEM(storage_V11, 0);
    {Py_XINCREF(py_V11);}
    
            V11 = NULL;
            if (py_V11 == Py_None) {
                // We can either fail here or set V11 to NULL and rely on Ops
                // using tensors to handle the NULL case, but if they fail to do so
                // they'll end up with nasty segfaults, so this is public service.
                PyErr_SetString(PyExc_ValueError, "expected an ndarray, not None");
                {
        __failure = 12;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
        }
        goto __label_12;}
            }
            if (!PyArray_Check(py_V11)) {
                PyErr_SetString(PyExc_ValueError, "expected an ndarray");
                {
        __failure = 12;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
        }
        goto __label_12;}
            }
            // We expect NPY_FLOAT64
            if (!PyArray_ISALIGNED((PyArrayObject*) py_V11)) {
                PyArrayObject * tmp = (PyArrayObject*) py_V11;
                PyErr_Format(PyExc_NotImplementedError,
                             "expected an aligned array of type %ld "
                             "(NPY_FLOAT64), got non-aligned array of type %ld"
                             " with %ld dimensions, with 3 last dims "
                             "%ld, %ld, %ld"
                             " and 3 last strides %ld %ld, %ld.",
                             (long int) NPY_FLOAT64,
                             (long int) PyArray_TYPE((PyArrayObject*) py_V11),
                             (long int) PyArray_NDIM(tmp),
                             (long int) (PyArray_NDIM(tmp) >= 3 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-3] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 2 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-2] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 1 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-1] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 3 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-3] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 2 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-2] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 1 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-1] : -1)
            );
                {
        __failure = 12;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
        }
        goto __label_12;}
            }
            // This is a TypeError to be consistent with DEBUG_MODE
            // Note: DEBUG_MODE also tells the name of the container
            if (PyArray_TYPE((PyArrayObject*) py_V11) != NPY_FLOAT64) {
                PyErr_Format(PyExc_TypeError,
                             "expected type_num %d (NPY_FLOAT64) got %d",
                             NPY_FLOAT64, PyArray_TYPE((PyArrayObject*) py_V11));
                {
        __failure = 12;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
        }
        goto __label_12;}
            }
            
        V11 = (PyArrayObject*)(py_V11);
        Py_XINCREF(V11);
        
{
// Op class Elemwise

        npy_float64* V11_iter;
        
                int V11_jumpx_0;
                
                npy_intp V11_n1;
                ssize_t V11_stride1;
                int V11_jump1_1;
                
                int V11_jumpx_2;
                
        npy_float64* V9_iter;
        
                int V9_jumpx_0;
                
                npy_intp V9_n1;
                ssize_t V9_stride1;
                int V9_jump1_1;
                
                int V9_jumpx_2;
                
        npy_float64* V7_iter;
        
                int V7_jumpx_0;
                
                npy_intp V7_n1;
                ssize_t V7_stride1;
                int V7_jump1_1;
                
                int V7_jumpx_2;
                
        npy_float64* V5_iter;
        
                int V5_jumpx_0;
                
                npy_intp V5_n1;
                ssize_t V5_stride1;
                int V5_jump1_1;
                
                int V5_jumpx_2;
                
        npy_float64* V3_iter;
        
                int V3_jumpx_0;
                
                npy_intp V3_n1;
                ssize_t V3_stride1;
                int V3_jump1_1;
                
                int V3_jumpx_2;
                

            if (PyArray_NDIM(V11) < 2) {
                PyErr_SetString(PyExc_ValueError, "Not enough dimensions on input.");
                {
        __failure = 13;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
        }
        goto __label_13;}
            }
            
                V11_jumpx_2 = -(0);
                
                V11_n1 = PyArray_DIMS(V11)[1];
                V11_stride1 = (V11_n1 == 1)? 0 : PyArray_STRIDES(V11)[1] / sizeof(npy_float64);
                V11_jump1_1 = (V11_stride1) - (0);
                
                V11_jumpx_0 = -(V11_n1*V11_stride1);
                
            if (PyArray_NDIM(V9) < 2) {
                PyErr_SetString(PyExc_ValueError, "Not enough dimensions on input.");
                {
        __failure = 13;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
        }
        goto __label_13;}
            }
            
                V9_jumpx_2 = -(0);
                
                V9_n1 = PyArray_DIMS(V9)[1];
                V9_stride1 = (V9_n1 == 1)? 0 : PyArray_STRIDES(V9)[1] / sizeof(npy_float64);
                V9_jump1_1 = (V9_stride1) - (0);
                
                V9_jumpx_0 = -(V9_n1*V9_stride1);
                
            if (PyArray_NDIM(V7) < 2) {
                PyErr_SetString(PyExc_ValueError, "Not enough dimensions on input.");
                {
        __failure = 13;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
        }
        goto __label_13;}
            }
            
                V7_jumpx_2 = -(0);
                
                V7_n1 = PyArray_DIMS(V7)[1];
                V7_stride1 = (V7_n1 == 1)? 0 : PyArray_STRIDES(V7)[1] / sizeof(npy_float64);
                V7_jump1_1 = (V7_stride1) - (0);
                
                V7_jumpx_0 = -(V7_n1*V7_stride1);
                
            if (PyArray_NDIM(V5) < 2) {
                PyErr_SetString(PyExc_ValueError, "Not enough dimensions on input.");
                {
        __failure = 13;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
        }
        goto __label_13;}
            }
            
                V5_jumpx_2 = -(0);
                
                V5_n1 = PyArray_DIMS(V5)[1];
                V5_stride1 = (V5_n1 == 1)? 0 : PyArray_STRIDES(V5)[1] / sizeof(npy_float64);
                V5_jump1_1 = (V5_stride1) - (0);
                
                V5_jumpx_0 = -(V5_n1*V5_stride1);
                
            if (PyArray_NDIM(V3) < 2) {
                PyErr_SetString(PyExc_ValueError, "Not enough dimensions on input.");
                {
        __failure = 13;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
        }
        goto __label_13;}
            }
            
                V3_jumpx_2 = -(0);
                
                V3_n1 = PyArray_DIMS(V3)[1];
                V3_stride1 = (V3_n1 == 1)? 0 : PyArray_STRIDES(V3)[1] / sizeof(npy_float64);
                V3_jump1_1 = (V3_stride1) - (0);
                
                V3_jumpx_0 = -(V3_n1*V3_stride1);
                
            npy_intp non1size_dim1;
            non1size_dim1 = (V11_n1 != 1) ? V11_n1 : (V9_n1 != 1) ? V9_n1 : (V7_n1 != 1) ? V7_n1 : (V5_n1 != 1) ? V5_n1 : V3_n1;
            if (non1size_dim1 != 1)
            {
        
                if ((V11_n1 != non1size_dim1) && (V11_n1 != 1))
                {
                    PyErr_Format(PyExc_ValueError, "Input dimension mismatch. One other input has shape[%i] = %lld, but input[%i].shape[%i] = %lld.",
                       1,
                       (long long int) non1size_dim1,
                       0,
                       1,
                       (long long int) V11_n1
                    );
                    {
        __failure = 13;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
        }
        goto __label_13;}
                }
            
                if ((V9_n1 != non1size_dim1) && (V9_n1 != 1))
                {
                    PyErr_Format(PyExc_ValueError, "Input dimension mismatch. One other input has shape[%i] = %lld, but input[%i].shape[%i] = %lld.",
                       1,
                       (long long int) non1size_dim1,
                       1,
                       1,
                       (long long int) V9_n1
                    );
                    {
        __failure = 13;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
        }
        goto __label_13;}
                }
            
                if ((V7_n1 != non1size_dim1) && (V7_n1 != 1))
                {
                    PyErr_Format(PyExc_ValueError, "Input dimension mismatch. One other input has shape[%i] = %lld, but input[%i].shape[%i] = %lld.",
                       1,
                       (long long int) non1size_dim1,
                       2,
                       1,
                       (long long int) V7_n1
                    );
                    {
        __failure = 13;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
        }
        goto __label_13;}
                }
            
                if ((V5_n1 != non1size_dim1) && (V5_n1 != 1))
                {
                    PyErr_Format(PyExc_ValueError, "Input dimension mismatch. One other input has shape[%i] = %lld, but input[%i].shape[%i] = %lld.",
                       1,
                       (long long int) non1size_dim1,
                       3,
                       1,
                       (long long int) V5_n1
                    );
                    {
        __failure = 13;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
        }
        goto __label_13;}
                }
            
                if ((V3_n1 != non1size_dim1) && (V3_n1 != 1))
                {
                    PyErr_Format(PyExc_ValueError, "Input dimension mismatch. One other input has shape[%i] = %lld, but input[%i].shape[%i] = %lld.",
                       1,
                       (long long int) non1size_dim1,
                       4,
                       1,
                       (long long int) V3_n1
                    );
                    {
        __failure = 13;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
        }
        goto __label_13;}
                }
            
            }
        

            if (V1) {
                Py_XDECREF(V1);
            }
            V1 = V11;
            Py_XINCREF(V1);
            

            if((PyArray_ISCONTIGUOUS(V11) && PyArray_ISCONTIGUOUS(V9) && PyArray_ISCONTIGUOUS(V7) && PyArray_ISCONTIGUOUS(V5) && PyArray_ISCONTIGUOUS(V3) && PyArray_ISCONTIGUOUS(V1)) || (PyArray_ISFORTRAN(V11) && PyArray_ISFORTRAN(V9) && PyArray_ISFORTRAN(V7) && PyArray_ISFORTRAN(V5) && PyArray_ISFORTRAN(V3) && PyArray_ISFORTRAN(V1))){
                
                    // All output have the same size
                    npy_intp n = PyArray_SIZE(V1);
                    
            dtype_V11 * V11_ptr = (dtype_V11*) PyArray_DATA(V11);
                            
            dtype_V9 * V9_ptr = (dtype_V9*) PyArray_DATA(V9);
                            
            dtype_V7 * V7_ptr = (dtype_V7*) PyArray_DATA(V7);
                            
            dtype_V5 * V5_ptr = (dtype_V5*) PyArray_DATA(V5);
                            
            dtype_V3 * V3_ptr = (dtype_V3*) PyArray_DATA(V3);
                            
            dtype_V1 * V1_ptr = (dtype_V1*) PyArray_DATA(V1);
                            
                    for(int i=0; i<n; i++){
                        
            dtype_V11& V11_i = V11_ptr[i];
                            
            dtype_V9& V9_i = V9_ptr[i];
                            
            dtype_V7& V7_i = V7_ptr[i];
                            
            dtype_V5& V5_i = V5_ptr[i];
                            
            dtype_V3& V3_i = V3_ptr[i];
                            
            dtype_V1& V1_i = V1_ptr[i];
                            
                        {
npy_float64 V13_tmp1;
V13_tmp1 = V3_i / V9_i;
npy_float64 V13_tmp2;
V13_tmp2 = V5_i / V9_i;
npy_float64 V13_tmp3;
V13_tmp3 = V13_tmp2 / V9_i;
npy_float64 V13_tmp4;
V13_tmp4 = V7_i / V9_i;
npy_float64 V13_tmp5;
V13_tmp5 = V11_i / V9_i;
npy_float64 V13_tmp6;
V13_tmp6 = V13_tmp5 / V9_i;
V1_i = V13_tmp6 + V13_tmp4 + V13_tmp3 + V13_tmp1;
}
;
                    }
                    
            }else{
                {

    std::vector< std::pair<int, int> > V11_loops(3);
    std::vector< std::pair<int, int> >::iterator V11_loops_it = V11_loops.begin();
    
            V11_loops_it->first = 0;
            
        V11_loops_it->second = 0;
        ++V11_loops_it;
        
            V11_loops_it->first = abs(PyArray_STRIDES(V11)[1]);
            
        V11_loops_it->second = 1;
        ++V11_loops_it;
        
            V11_loops_it->first = 0;
            
        V11_loops_it->second = 2;
        ++V11_loops_it;
        
    // rbegin and rend are reversed iterators, so this sorts in decreasing order
    std::sort(V11_loops.rbegin(), V11_loops.rend());
    
int init_totals[3];
init_totals[0] = 1;
init_totals[1] = (V11_n1 != 1)? V11_n1: (V9_n1 != 1)? V9_n1: (V7_n1 != 1)? V7_n1: (V5_n1 != 1)? V5_n1: V3_n1;
init_totals[2] = 1;

    V11_loops_it = V11_loops.begin();
    
        int TOTAL_0 = init_totals[V11_loops_it->second];
        ++V11_loops_it;
        
        int TOTAL_1 = init_totals[V11_loops_it->second];
        ++V11_loops_it;
        
        int TOTAL_2 = init_totals[V11_loops_it->second];
        ++V11_loops_it;
        

    int init_strides[5][3] = {
        0, V11_stride1, 0, 
0, V9_stride1, 0, 
0, V7_stride1, 0, 
0, V5_stride1, 0, 
0, V3_stride1, 0
    };
    std::vector< std::pair<int, int> >::reverse_iterator V11_loops_rit;
    
        V11_loops_rit = V11_loops.rbegin();
            int V11_stride_l2 = init_strides[0][V11_loops_rit->second];
            ++V11_loops_rit;
            
            int V11_stride_l1 = init_strides[0][V11_loops_rit->second];
            ++V11_loops_rit;
            
            int V11_stride_l0 = init_strides[0][V11_loops_rit->second];
            ++V11_loops_rit;
            
        V11_loops_rit = V11_loops.rbegin();
            int V9_stride_l2 = init_strides[1][V11_loops_rit->second];
            ++V11_loops_rit;
            
            int V9_stride_l1 = init_strides[1][V11_loops_rit->second];
            ++V11_loops_rit;
            
            int V9_stride_l0 = init_strides[1][V11_loops_rit->second];
            ++V11_loops_rit;
            
        V11_loops_rit = V11_loops.rbegin();
            int V7_stride_l2 = init_strides[2][V11_loops_rit->second];
            ++V11_loops_rit;
            
            int V7_stride_l1 = init_strides[2][V11_loops_rit->second];
            ++V11_loops_rit;
            
            int V7_stride_l0 = init_strides[2][V11_loops_rit->second];
            ++V11_loops_rit;
            
        V11_loops_rit = V11_loops.rbegin();
            int V5_stride_l2 = init_strides[3][V11_loops_rit->second];
            ++V11_loops_rit;
            
            int V5_stride_l1 = init_strides[3][V11_loops_rit->second];
            ++V11_loops_rit;
            
            int V5_stride_l0 = init_strides[3][V11_loops_rit->second];
            ++V11_loops_rit;
            
        V11_loops_rit = V11_loops.rbegin();
            int V3_stride_l2 = init_strides[4][V11_loops_rit->second];
            ++V11_loops_rit;
            
            int V3_stride_l1 = init_strides[4][V11_loops_rit->second];
            ++V11_loops_rit;
            
            int V3_stride_l0 = init_strides[4][V11_loops_rit->second];
            ++V11_loops_rit;
            
V11_iter = (npy_float64*)(PyArray_DATA(V11));
V9_iter = (npy_float64*)(PyArray_DATA(V9));
V7_iter = (npy_float64*)(PyArray_DATA(V7));
V5_iter = (npy_float64*)(PyArray_DATA(V5));
V3_iter = (npy_float64*)(PyArray_DATA(V3));


        for(int ITER_0 = 0; ITER_0<TOTAL_0; ITER_0++)
        { // begin loop 0
            
            
        for(int ITER_1 = 0; ITER_1<TOTAL_1; ITER_1++)
        { // begin loop 1
            
            
        for(int ITER_2 = 0; ITER_2<TOTAL_2; ITER_2++)
        { // begin loop 2
            npy_float64 &V11_i = * ( V11_iter+V11_stride_l2*ITER_2+V11_stride_l1*ITER_1+V11_stride_l0*ITER_0);
npy_float64 &V9_i = * ( V9_iter+V9_stride_l2*ITER_2+V9_stride_l1*ITER_1+V9_stride_l0*ITER_0);
npy_float64 &V7_i = * ( V7_iter+V7_stride_l2*ITER_2+V7_stride_l1*ITER_1+V7_stride_l0*ITER_0);
npy_float64 &V5_i = * ( V5_iter+V5_stride_l2*ITER_2+V5_stride_l1*ITER_1+V5_stride_l0*ITER_0);
npy_float64 &V3_i = * ( V3_iter+V3_stride_l2*ITER_2+V3_stride_l1*ITER_1+V3_stride_l0*ITER_0);

            
        {
            #define V1_i V11_i

            {
npy_float64 V13_tmp1;
V13_tmp1 = V3_i / V9_i;
npy_float64 V13_tmp2;
V13_tmp2 = V5_i / V9_i;
npy_float64 V13_tmp3;
V13_tmp3 = V13_tmp2 / V9_i;
npy_float64 V13_tmp4;
V13_tmp4 = V7_i / V9_i;
npy_float64 V13_tmp5;
V13_tmp5 = V11_i / V9_i;
npy_float64 V13_tmp6;
V13_tmp6 = V13_tmp5 / V9_i;
V1_i = V13_tmp6 + V13_tmp4 + V13_tmp3 + V13_tmp1;
}

            #undef V1_i

        }
        
        } // end loop 2
        
        } // end loop 1
        
        } // end loop 0
        
}

            }
            
__label_13:

double __DUMMY_13;

}
__label_12:

        if (V11) {
            Py_XDECREF(V11);
        }
        
    {Py_XDECREF(py_V11);}
    
double __DUMMY_12;

}
__label_10:

        if (V9) {
            Py_XDECREF(V9);
        }
        
    {Py_XDECREF(py_V9);}
    
double __DUMMY_10;

}
__label_8:

        if (V7) {
            Py_XDECREF(V7);
        }
        
    {Py_XDECREF(py_V7);}
    
double __DUMMY_8;

}
__label_6:

        if (V5) {
            Py_XDECREF(V5);
        }
        
    {Py_XDECREF(py_V5);}
    
double __DUMMY_6;

}
__label_4:

        if (V3) {
            Py_XDECREF(V3);
        }
        
    {Py_XDECREF(py_V3);}
    
double __DUMMY_4;

}
__label_2:

    if (!__failure) {
      
        {Py_XDECREF(py_V1);}
        if (!V1) {
            Py_INCREF(Py_None);
            py_V1 = Py_None;
        }
        else if ((void*)py_V1 != (void*)V1) {
            py_V1 = (PyObject*)V1;
        }

        {Py_XINCREF(py_V1);}

        if (V1 && !PyArray_ISALIGNED((PyArrayObject*) py_V1)) {
            PyErr_Format(PyExc_NotImplementedError,
                         "c_sync: expected an aligned array, got non-aligned array of type %ld"
                         " with %ld dimensions, with 3 last dims "
                         "%ld, %ld, %ld"
                         " and 3 last strides %ld %ld, %ld.",
                         (long int) PyArray_TYPE((PyArrayObject*) py_V1),
                         (long int) PyArray_NDIM(V1),
                         (long int) (PyArray_NDIM(V1) >= 3 ?
        PyArray_DIMS(V1)[PyArray_NDIM(V1)-3] : -1),
                         (long int) (PyArray_NDIM(V1) >= 2 ?
        PyArray_DIMS(V1)[PyArray_NDIM(V1)-2] : -1),
                         (long int) (PyArray_NDIM(V1) >= 1 ?
        PyArray_DIMS(V1)[PyArray_NDIM(V1)-1] : -1),
                         (long int) (PyArray_NDIM(V1) >= 3 ?
        PyArray_STRIDES(V1)[PyArray_NDIM(V1)-3] : -1),
                         (long int) (PyArray_NDIM(V1) >= 2 ?
        PyArray_STRIDES(V1)[PyArray_NDIM(V1)-2] : -1),
                         (long int) (PyArray_NDIM(V1) >= 1 ?
        PyArray_STRIDES(V1)[PyArray_NDIM(V1)-1] : -1)
        );
            {
        __failure = 2;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
        }
        goto __label_2;}
        }
        
      PyObject* old = PyList_GET_ITEM(storage_V1, 0);
      {Py_XINCREF(py_V1);}
      PyList_SET_ITEM(storage_V1, 0, py_V1);
      {Py_XDECREF(old);}
    }
    
        if (V1) {
            Py_XDECREF(V1);
        }
        
    {Py_XDECREF(py_V1);}
    
double __DUMMY_2;

}

            
        if (__failure) {
            // When there is a failure, this code puts the exception
            // in __ERROR.
            PyObject* err_type = NULL;
            PyObject* err_msg = NULL;
            PyObject* err_traceback = NULL;
            PyErr_Fetch(&err_type, &err_msg, &err_traceback);
            if (!err_type) {err_type = Py_None;Py_INCREF(Py_None);}
            if (!err_msg) {err_msg = Py_None; Py_INCREF(Py_None);}
            if (!err_traceback) {err_traceback = Py_None; Py_INCREF(Py_None);}
            PyObject* old_err_type = PyList_GET_ITEM(__ERROR, 0);
            PyObject* old_err_msg = PyList_GET_ITEM(__ERROR, 1);
            PyObject* old_err_traceback = PyList_GET_ITEM(__ERROR, 2);
            PyList_SET_ITEM(__ERROR, 0, err_type);
            PyList_SET_ITEM(__ERROR, 1, err_msg);
            PyList_SET_ITEM(__ERROR, 2, err_traceback);
            {Py_XDECREF(old_err_type);}
            {Py_XDECREF(old_err_msg);}
            {Py_XDECREF(old_err_traceback);}
        }
        // The failure code is returned to index what code block failed.
        return __failure;
        
        }
    };
    }
    

        static int __struct_compiled_op_m158937ba65a097497b84a2324371ae53dfd7c158755888832b5ed5e7530f673a_executor(__struct_compiled_op_m158937ba65a097497b84a2324371ae53dfd7c158755888832b5ed5e7530f673a *self) {
            return self->run();
        }

        static void __struct_compiled_op_m158937ba65a097497b84a2324371ae53dfd7c158755888832b5ed5e7530f673a_destructor(PyObject *capsule) {
            __struct_compiled_op_m158937ba65a097497b84a2324371ae53dfd7c158755888832b5ed5e7530f673a *self = (__struct_compiled_op_m158937ba65a097497b84a2324371ae53dfd7c158755888832b5ed5e7530f673a *)PyCapsule_GetContext(capsule);
            delete self;
        }
    
//////////////////////
////  Functions
//////////////////////
static PyObject * instantiate(PyObject * self, PyObject *argtuple) {
  assert(PyTuple_Check(argtuple));
  if (7 != PyTuple_Size(argtuple)){ 
     PyErr_Format(PyExc_TypeError, "Wrong number of arguments, expected 7, got %i", (int)PyTuple_Size(argtuple));
     return NULL;
  }
  __struct_compiled_op_m158937ba65a097497b84a2324371ae53dfd7c158755888832b5ed5e7530f673a* struct_ptr = new __struct_compiled_op_m158937ba65a097497b84a2324371ae53dfd7c158755888832b5ed5e7530f673a();
  if (struct_ptr->init( PyTuple_GET_ITEM(argtuple, 0),PyTuple_GET_ITEM(argtuple, 1),PyTuple_GET_ITEM(argtuple, 2),PyTuple_GET_ITEM(argtuple, 3),PyTuple_GET_ITEM(argtuple, 4),PyTuple_GET_ITEM(argtuple, 5),PyTuple_GET_ITEM(argtuple, 6) ) != 0) {
    delete struct_ptr;
    return NULL;
  }
    PyObject* thunk = PyCapsule_New((void*)(&__struct_compiled_op_m158937ba65a097497b84a2324371ae53dfd7c158755888832b5ed5e7530f673a_executor), NULL, __struct_compiled_op_m158937ba65a097497b84a2324371ae53dfd7c158755888832b5ed5e7530f673a_destructor);
    if (thunk != NULL && PyCapsule_SetContext(thunk, struct_ptr) != 0) {
        PyErr_Clear();
        Py_DECREF(thunk);
        thunk = NULL;
    }

  return thunk; }

//////////////////////
////  Module init
//////////////////////
static PyMethodDef MyMethods[] = {
	{"instantiate", instantiate, METH_VARARGS, "undocumented"} ,
	{NULL, NULL, 0, NULL}
};
static struct PyModuleDef moduledef = {
  PyModuleDef_HEAD_INIT,
  "m158937ba65a097497b84a2324371ae53dfd7c158755888832b5ed5e7530f673a",
  NULL,
  -1,
  MyMethods,
};

PyMODINIT_FUNC PyInit_m158937ba65a097497b84a2324371ae53dfd7c158755888832b5ed5e7530f673a(void) {
   import_array();
   
    PyObject *m = PyModule_Create(&moduledef);
    return m;
}
