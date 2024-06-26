#pragma once
#include "graph.hpp"
#include <raymath.h>
#include "vectormath.hpp"

class Simulation {
    Graph graph;
    uint32_t width;
    uint32_t height;

public:
    Simulation(Graph graph, uint32_t width, uint32_t height) : graph(graph), width(width), height(height) {
        for (Node &node : graph.nodes) {
            node.last_position = node.current_position;
        }
    }

    void update(float dt) {
        verlet(dt);
        relaxEdges();
        constrain();
    }

    void verlet(float dt) {
        for (Node &node : graph.nodes) {
            Vector2 velocity = node.current_position - node.last_position;
            node.last_position = node.current_position;
            node.current_position += velocity + node.acceleration * dt * dt;
        }
    }

    void relaxEdges() {
        for (Edge &edge : graph.edges) {
            Vector2 direction = edge.node2->current_position - edge.node1->current_position;
            float distance = Vector2Length(direction);
            float difference = edge.length - distance;
            Vector2 correction = Vector2Normalize(direction) * difference;
            edge.node1->current_position -= correction * 0.5f;
            edge.node2->current_position += correction * 0.5f;
        }
    }

    void constrain() {
        for (Node &node : graph.nodes) {
            if (node.current_position.x - node.radius < 0) {
                node.current_position.x = node.radius;
            } else if (node.current_position.x + node.radius > width) {
                node.current_position.x = width - node.radius;
            }

            if (node.current_position.y - node.radius < 0) {
                node.current_position.y = node.radius;
            } else if (node.current_position.y + node.radius > height) {
                node.current_position.y = height - node.radius;
            }
        }
    }
};
