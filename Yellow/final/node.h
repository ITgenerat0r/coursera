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
	virtual bool Evaluate(const Date& date, const std::string& event) const = 0;
};



class EmptyNode : public Node {
	bool Evaluate(const Date& date, const std::string& event);
};


class DateComparisonNode : public Node {
public:
	DateComparisonNode(const Comparison& cmp, const Date& d) : comparison(cmp), date(d) {}
	bool Evaluate(const Date& date, const std::string& event);
private:
	const Comparison comparison;
	const Date date;
};


class EventComparisonNode : public Node {
public:
	EventComparisonNode(const Comparison& cmp, const std::string& v) : comparison(cmp), value(v) {}
	bool Evaluate(const Date& date, const std::string& event);
private:
	const Comparison comparison;
	const std::string value;
};



class LogicalOperationNode : public Node {
public:
	LogicalOperationNode(const LogicalOperation& lo, 
						const std::shared_ptr<Node>& l, 
						const std::shared_ptr<Node> r) 
						: logical_operation(lo), left(l), right(r) {}
	bool Evaluate(const Date& date, const std::string& event);
private:
	const LogicalOperation logical_operation;
	const std::shared_ptr<Node> left;
	const std::shared_ptr<Node> right;	
};