# -*- coding:utf-8 -*-
class Employee:
    def __init__(self, name, employee_id):
        self.name = name
        self.id = employee_id

    def calculate_salary(self):
        pass

    def get_salary(self):
        return self.calculate_salary()

    def print_info(self):
        print(f"Name: {self.name}")
        print(f"ID: {self.id}")
        print(f"Salary: {self.get_salary()}")


class MonthlyEmployee(Employee):
    def __init__(self, name, employee_id, monthly_salary):
        super().__init__(name, employee_id)
        self.monthly_salary = monthly_salary

    def calculate_salary(self):
        return self.monthly_salary


class DailyEmployee(Employee):
    def __init__(self, name, employee_id, daily_rate):
        super().__init__(name, employee_id)
        self.daily_rate = daily_rate

    def calculate_salary(self, days_worked):
        return self.daily_rate * days_worked


# ����һ����нԱ��ʵ��
employee1 = MonthlyEmployee("Alice", 12345, 3000)

# ����һ����нԱ��ʵ��
employee2 = DailyEmployee("Bob", 67890, 100)

# ��ӡԱ������Ϣ�͹���
employee1.print_info()
employee2.print_info()