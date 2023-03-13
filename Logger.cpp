#include "Logger.h"

Logger::Logger(Graph* graph) {
    this->graph = graph;
}

void Logger::printGraphEdges() {
    string ret;
    for (const auto &[key, val] : graph->edges){
        ret += to_string(key->getData()) += " --> ";
        for (auto node : val){
            ret += to_string(node->getData()) += ", ";
        }
        ret += "\n";
    }
    cout << ret;
}

void Logger::printGraphNodes() {
    string ret;
    for (auto node : graph->nodes) {
        ret += "Data: ";
        ret += to_string(node->getData());
    }
    cout << ret;
}

void Logger::printGraphMatching() {

}
