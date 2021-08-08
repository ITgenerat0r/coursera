#pragma once

#include "date.h"

#include <memory>


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
public:
	Node(std::string s) : type(s) {}
	virtual bool Evaluate(const Date& date, const std::string& event) const = 0;
private:
	std::string type;
};



class EmptyNode : public Node {
public:
	EmptyNode() : Node("empty") {}
	bool Evaluate(const Date& date, const std::string& event) const override;
};


class DateComparisonNode : public Node {
public:
	DateComparisonNode(const Comparison& cmp, const Date& d) : Node("date"), comparison(cmp), date(d) {}
	bool Evaluate(const Date& date, const std::string& event) const override;
private:
	const Comparison comparison;
	const Date date;
};


class EventComparisonNode : public Node {
public:
	EventComparisonNode(const Comparison& cmp, const std::string& v) : Node("event"), comparison(cmp), value(v) {}
	bool Evaluate(const Date& date, const std::string& event) const override;
private:
	const Comparison comparison;
	const std::string value;
};



class LogicalOperationNode : public Node {
public:
	LogicalOperationNode(const LogicalOperation& lo, 
						const std::shared_ptr<Node>& l, 
						const std::shared_ptr<Node> r) 
						: Node("logic"), logical_operation(lo), left(l), right(r) {}
	bool Evaluate(const Date& date, const std::string& event) const override;
private:
	const LogicalOperation logical_operation;
	const std::shared_ptr<Node> left;
	const std::shared_ptr<Node> right;	
};