import tkinter as tk

class Producto:
    def __init__(self, nombre, precio, stock_inicial):
        self.nombre = nombre
        self.precio = precio
        self.stock = stock_inicial

class Inventario:
    def __init__(self):
        self.productos = []

    def agregar_producto(self, producto):
        self.productos.append(producto)

    def eliminar_producto(self, nombre_producto):
        for producto in self.productos:
            if producto.nombre == nombre_producto:
                self.productos.remove(producto)
                break
        else:
            print("Producto no encontrado en el inventario.")

    def actualizar_stock(self, nombre_producto, cantidad_vendida):
        for producto in self.productos:
            if producto.nombre == nombre_producto:
                producto.stock -= cantidad_vendida
                print(f"{cantidad_vendida} {nombre_producto}(s) vendidos. Stock restante: {producto.stock}")
                break
        else:
            print("Producto no encontrado en el inventario.")

    def mostrar_inventario(self):
        for producto in self.productos:
            print(f"Producto: {producto.nombre}, Precio: ${producto.precio}, Stock: {producto.stock}")

class Interfaz:
    def __init__(self, ventana):
        self.ventana = ventana
        self.ventana.title("Friduchas Wings")

        self.label = tk.Label(ventana, text="Bienvenido a Friduchas Wings", font=("Arial", 16))
        self.label.pack()

        self.boton_agregar = tk.Button(ventana, text="Agregar Producto", command=self.agregar_producto)
        self.boton_agregar.pack()

        self.boton_vender = tk.Button(ventana, text="Vender Producto", command=self.vender_producto)
        self.boton_vender.pack()

        self.boton_mostrar = tk.Button(ventana, text="Mostrar Inventario", command=self.mostrar_inventario)
        self.boton_mostrar.pack()

        self.inventario = Inventario()

    def agregar_producto(self):
        nombre = input("Ingresa el nombre del producto: ")
        precio = float(input("Ingresa el precio del producto: "))
        stock = int(input("Ingresa la cantidad inicial en stock: "))
        producto = Producto(nombre, precio, stock)
        self.inventario.agregar_producto(producto)

    def vender_producto(self):
        nombre_producto = input("Ingresa el nombre del producto vendido: ")
        cantidad_vendida = int(input("Ingresa la cantidad vendida: "))
        self.inventario.actualizar_stock(nombre_producto, cantidad_vendida)

    def mostrar_inventario(self):
        self.inventario.mostrar_inventario()

if __name__ == "__main__":
    ventana = tk.Tk()
    app = Interfaz(ventana)
    ventana.mainloop()
