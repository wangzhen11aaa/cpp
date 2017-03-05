//
// Created by wangzhen on 05/03/2017.
//

#ifndef CPP_BOOK_EMP_H
#define CPP_BOOK_EMP_H
#include <iostream>
#include <string>

using std::string;
class abstr_emp
{
private:
    std::string fname; // abstr_emp's first name
    std::string lname; // abstr_emp's last name
    std::string job;
public:
    abstr_emp(); //default constructor
    abstr_emp(const std::string &fn, const std::string &ln, const std::string &j);
    virtual void ShowAll() const; //labels and show all data
    virtual void SetAll();  //prompts user for values
    friend std::ostream & operator<<(std::ostream &os, const abstr_emp &e);
    //just displays first and last name
    virtual ~abstr_emp() = 0; // virtual base class
};

class employee:public abstr_emp
{
public:
    employee();
    employee(const std::string &fn, const std::string &ln, const string & j);
    virtual void ShowAll() const;
    virtual void SetAll();

};

class manager: virtual public abstr_emp
{
private:
    int inchageof; //number of abstr_emps managed
protected:
    int InChargeOf() const {return inchageof;} //output
    int & InChargeOf() {return inchageof;} // for input
public:
    manager();
    manager(const std::string &fn, const std::string &ln, const std::string &j, int ico = 0);
    manager(const abstr_emp &e, int ico);
    manager(const manager &m);
    virtual void ShowAll() const;
    virtual void SetAll();

};

class fink: virtual public abstr_emp
{
private:
    std::string reportsto; // to whom fink reports
protected:
    const std::string ReportsTo() const {return reportsto;}
    std::string & ReportsTo() {return reportsto;}
public:
    fink();
    fink(const std::string &fn ,const std::string &ln, const std::string &j, const std::string &rpo);
    fink(const abstr_emp &e, const std::string &rpo);
    fink(const fink & e);
    virtual void ShowAll() const;
    virtual void SetAll();
};

class highfink:public manager, public fink // manager fink
{
public:
    highfink();
    highfink(const std::string &fn, const std::string &ln, const std::string &j, const std::string & rpo, int ico);
    highfink(const abstr_emp & e, const std::string & rpo, int ico);
    highfink(const fink &f, int ico);
    highfink(const manager &m, const std::string & rpo);
    highfink(const highfink &h);
    virtual void ShowAll() const;
    virtual void SetAll();
};

#endif //CPP_BOOK_EMP_H
