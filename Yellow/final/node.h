#pragma once

enum class Comparison {
  Less,
  LessOrEqual,
  Greater,
  GreaterOrEqual,
  Equal,
  NotEqual,
};

enum class LogicalOperation {
	And, 
	Or,
};

class Node {
	
};



class EmptyNode : public Node {

};


class DateComparisonNode : public Node {
public:
	DateComparisonNode(const Comparison& cmp, const Date& d) : comparison(cmp), date(d) {}
private:
	const Comparison comparison;
	const Date date;
};


class EventComparisonNode : public Node {
public:
	EventComparisonNode(const Comparison& cmp, const string& v) : comparison(cmp), value(v) {}
private:
	const Comparison comparison;
	const string value;
};


class LogicalOperationNode : public Node {
public:
	LogicalOperationNode(const LogicalOperation& lo, 
						const shared_ptr<Node>& l, 
						const shared_ptr<Node> r) 
						: logical_operation(lo), left(l), right(r) {}
private:
	const LogicalOperation logical_operation;
	const shared_ptr<Node> left;
	const shared_ptr<Node> right;	
};