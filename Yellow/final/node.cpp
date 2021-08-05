#include "node.h"

using namespace std;


bool EmptyNode::Evaluate(const Date& date, const std::string& event){
	return false;
}


bool DateComparisonNode::Evaluate(const Date& date, const std::string& event){
	return false;
}


bool EventComparisonNode::Evaluate(const Date& date, const std::string& event){
	return false;
}


bool LogicalOperationNode::Evaluate(const Date& date, const std::string& event){
	return false;
}