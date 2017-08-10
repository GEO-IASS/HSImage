#define PY_ARRAY_UNIQUE_SYMBOL pbcvt_ARRAY_API

#include <boost/python.hpp>

#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

#include "pybind11_opencv_numpy/pybind11/pybind11.h"
#include "pybind11_opencv_numpy/pybind11/stl.h"
#include "pybind11_opencv_numpy/pybind11/stl_bind.h"

#include "labelfile.h"
#include "classifiedhsimage.h"
#include "hsimage.h"
#include "pyboostconverter/pyboostcvconverter.hpp"

#include "pybind11_opencv_numpy/ndarray_converter.h"



//declarations for Python class exports
void export_labelfile();
void export_hsimage();
void export_classifiedhsimage();


#if (PY_VERSION_HEX >= 0x03000000)

    static void *init_ar() {
#else
        static void init_ar(){
#endif
        Py_Initialize();

        import_array();
        return NUMPY_IMPORT_ARRAY_RETVAL;
    }

PYBIND11_MAKE_OPAQUE(std::vector<std::string>)
PYBIND11_MAKE_OPAQUE(std::vector<u_int16_t>)
PYBIND11_MAKE_OPAQUE(std::vector<std::vector<u_int16_t> >)
PYBIND11_MAKE_OPAQUE(std::vector<double>)
PYBIND11_MAKE_OPAQUE(std::vector<std::vector<double> >)
PYBIND11_MAKE_OPAQUE(std::vector<float>)
PYBIND11_MAKE_OPAQUE(std::vector<cv::Mat>)
PYBIND11_MAKE_OPAQUE(std::vector<classColor>)


PYBIND11_PLUGIN(HSI)
{
    namespace py = pybind11;

    py::module m("HSI","Python interface module for ENVI-BIL hyperspectral images");

    NDArrayConverter::init_numpy();

    py::bind_vector<std::vector<std::string> >(m, "StringVector");
    py::bind_vector<std::vector<u_int16_t> >(m, "UInt16Vector");
    py::bind_vector<std::vector<std::vector<u_int16_t> > >(m, "UInt16VectorArray");
    py::bind_vector<std::vector<double> >(m, "DoubleVector");
    py::bind_vector<std::vector<std::vector<double> > >(m, "DoubleVectorArray");
    py::bind_vector<std::vector<float> >(m, "FloatVector");
    py::bind_vector<std::vector<cv::Mat> >(m, "MatVector");
    py::bind_vector<std::vector<classColor> >(m, "ClassInfoVector");




    return m.ptr();
}


//BOOST_PYTHON_MODULE(HSI)
//{
//    namespace bp = boost::python;

//    // specify that this module is actually a package
//    bp::object package = bp::scope();
//    package.attr("__path__") = "HSI";

//    init_ar();

//   //initialize converters
//    boost::python::to_python_converter<cv::Mat,
//           pbcvt::matToNDArrayBoostConverter>();
//    pbcvt::matFromNDArrayBoostConverter();

//    boost::python::to_python_converter<cv::Vec3b,
//	    cv_vec3b_to_python_converter>();

//    iterable_converter()
//            .from_python<std::vector<float>> () \
//            .from_python<std::vector<std::string>> () \
//    ;

//    std_pair_to_python_converter<std::string, cv::Vec3b>();

//    MAKE_VECTOR_WRAPPER(std::vector<std::string>, stringVector);
//    MAKE_VECTOR_WRAPPER(std::vector<u_int16_t>, uint16Vector);
//    MAKE_VECTOR_WRAPPER(std::vector<std::vector<u_int16_t>>, classSpectraArray);
//    MAKE_VECTOR_WRAPPER(std::vector<std::vector<double>>, classTFArray);
//    MAKE_VECTOR_WRAPPER(std::vector<double>, doubleVector);
//    MAKE_VECTOR_WRAPPER(std::vector<float>, floatVector);
//    MAKE_VECTOR_WRAPPER_LIMITED(std::vector<cv::Mat>, cvMatVector);
//    MAKE_VECTOR_WRAPPER_LIMITED(std::vector<classColor>, classInfoVector);

//    export_labelfile();
//    export_hsimage();
//    export_classifiedhsimage();
//}
