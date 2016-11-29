/* ************************************************************************
	> File Name: CompanySalary.java
	> Author: caowushang
	> Mail: 15630929347@163.com 
	> Created Time: 2016年11月01日 星期二 18时30分21秒
 ************************************************************************/
abstract class Employee{
	public abstract double earnings();
}
class YearWorker extends Employee{
	public double earnings(){
		return 240000;
	}
}
class MonthWorker extends Employee{
	public double earnings(){
		return 12*18000;
	}
}
class WeekWorker extends Employee{
	public double earnings(){
		return (12*4+2)*3000;
	}
}
class Company{
	Employee[] employee;
	double salaries=0;
	Company(Employee[] employee){
		this.employee=employee;
	}
	public double salariesPay(){
		salaries=0;
		for(int i=0;i<employee.length;i++){
			salaries+=employee[i].earnings();
		}
		return salaries;
	}
}
public class CompanySalary{
	public static void main(String args[]){
		Employee[] employee=new Employee[29];
		for(int i=0;i<employee.length;i++){
			if(i%3==0)
				employee[i]=new WeekWorker();
			else if(i%3==1)
				employee[i]=new MonthWorker();
			else
				employee[i]=new YearWorker();
			System.out.printf("员工ID:%d  年薪：%f\n",i,employee[i].earnings());
		}
		Company company=new Company(employee);
		System.out.println("公司薪水总额："+company.salariesPay()+"元");
	}
}
