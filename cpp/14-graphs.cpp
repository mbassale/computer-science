#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <set>
#include <boost/graph/adjacency_list.hpp>


TEST_CASE("boost:adjacency_list stores graph data") {
    boost::adjacency_list<> graph{};
    auto vertex1 = boost::add_vertex(graph);
    auto vertex2 = boost::add_vertex(graph);
    auto vertex3 = boost::add_vertex(graph);
    auto vertex4 = boost::add_vertex(graph);
    auto edge12 = boost::add_edge(vertex1, vertex2, graph);
    auto edge13 = boost::add_edge(vertex1, vertex3, graph);
    auto edge21 = boost::add_edge(vertex2, vertex1, graph);
    auto edge24 = boost::add_edge(vertex2, vertex4, graph);
    auto edge43 = boost::add_edge(vertex4, vertex3, graph);

    REQUIRE(boost::num_vertices(graph) == 4);
    REQUIRE(boost::num_edges(graph) == 5);

    auto [begin, end] = boost::adjacent_vertices(vertex1, graph);
    std::set<decltype(vertex1)> neighbours1{ begin, end };
    REQUIRE(neighbours1.count(vertex2) == 1);
    REQUIRE(neighbours1.count(vertex3) == 1);
    REQUIRE(neighbours1.count(vertex4) == 0);
}
