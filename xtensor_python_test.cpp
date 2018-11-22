#include <iostream>
#include <ostream>

#include <pybind11/pybind11.h>

#define FORCE_IMPORT_ARRAY // for numpy API
#include <xtensor/xarray.hpp>  // for xt::xarray
#include <xtensor/xio.hpp>  // for std::cout of xt::xarray
#include <xtensor-python/pyarray.hpp>  // for xt::pyarray

namespace py = pybind11;


struct Point {
    int64_t x;
    int64_t y;
};


std::ostream& operator<< (std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}


class PointCollection {
 public:
    PointCollection(xt::pyarray<Point> points) : points_(points) {}

    const xt::xarray<Point> points() const {
        return points_;
    }

 private:
    xt::xarray<Point> points_;
};


PYBIND11_MODULE(xtensor_python_test, m) {
    xt::import_numpy();

    // Point
    PYBIND11_NUMPY_DTYPE(Point, x, y);
    py::class_<Point> p (m, "Point");
    p.def(py::init<int64_t, int64_t>());
    p.attr("dtype") = py::dtype::of<Point>();

    // PointCollection
    py::class_<PointCollection> pc (m, "PointCollection");
    pc.def(py::init<xt::pyarray<Point>>());
    pc.def_property_readonly("points", &PointCollection::points);
}
