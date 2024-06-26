#pragma once
#include <raylib.h>
#include <vector>

struct Node {
    Vector2 current_position;
    Vector2 last_position;
    Vector2 acceleration;
    float radius;
};

struct Edge {
    Node *node1;
    Node *node2;
    float length;
};

struct Graph {
    std::vector<Node> nodes;
    std::vector<Edge> edges;
};
