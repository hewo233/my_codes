class Employee:
    def __init__(self,name,id):
        self.name = name
        self.id = id
    
    def calculate_salary(self):
        pass

    def get_month_salary(self):
        return self.calculate_salary()

    def print_info(self):
        print(f"this is {self.name},his id is {self.id},he got {self.get_month_salary()} per month")

class month_employee(Employee):
    def __init__(self,name,id,month_salary):
        super().__init__(name,id)
        self.month_salary = month_salary
    
    def calculate_salary(self):
        return self.month_salary
    
    
class day_employee(Employee):
    def __init__(self,name,id,day_salary,work_days):
        super().__init__(name,id)
        self.day_salary=day_salary
        self.work_days=work_days

    def calculate_salary(self):
        return self.work_days * self.day_salary
    
a1 = month_employee('hewo',233,100000)
a2 = day_employee('hexo',114514,1000,15)

a1.print_info()
a2.print_info()


    

    
