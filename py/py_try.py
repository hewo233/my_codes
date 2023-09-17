class Vehicle:
    def __init__(self, brand, model, year):
        self.brand = brand
        self.model = model
        self.year = year

    def start_engine(self):
        print(f"The {self.brand} {self.model}'s engine is starting.")

    def stop_engine(self):
        print(f"The {self.brand} {self.model}'s engine is stopping.")


class Car(Vehicle):
    def __init__(self, brand, model, year, num_doors):
        super().__init__(brand, model, year)
        self.num_doors = num_doors

    def open_doors(self):
        print(f"The {self.brand} {self.model} has {self.num_doors} doors. Opening doors.")


my_car = Car("Toyota", "Corolla", 2022, 4)
print(my_car.brand)     # Output: Toyota
print(my_car.model)     # Output: Corolla
print(my_car.year)      # Output: 2022
print(my_car.num_doors) # Output: 4
my_car.start_engine()   # Output: The Toyota Corolla's engine is starting.
my_car.stop_engine()    # Output: The Toyota Corolla's engine is stopping.
my_car.open_doors()     # Output: The Toyota Corolla has 4 doors. Opening doors.