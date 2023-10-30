# Reporte de cambios

&nbsp; Este documento contiene información referida a los avances en el desarrollo de Baluma ERP. Para cada versión del mismo se muestran las modificaciones realizadas, brevemente explicadas en el módulo afectado. También se describen implementaciones propuestas a futuro. El versionado semántico se lleva a cabo considerando la siguiente [documentación](https://semver.org).

## Versión 1.0.0

&nbsp; La primera versión de Baluma ERP fue desarrollada en un lapso de 2 meses entre 3 personas, habiéndose invertido aproximadamente 300 horas netas en total. Incorpora 4 de los 5 módulos propuestos:

- [x] Socios de negocios
- [x] Inventario
- [x] Contabilidad
- [x] Recursos humanos
- [ ] Presupuestos

### Socios de negocios

_Desarrollado por: Maximiliano Malvicino_

&nbsp; El módulo fue desarrollado en su totalidad. Permite gestionar el CRUD (alta, modificación, baja lógica y listado) de socios y proveedores. También cuenta con opciones de exportación e importación en formatos .bkp y .csv.

### Inventario

_Desarrollado por: Maximiliano Malvicino, Franco Baez_

&nbsp; El módulo fue desarrollado en su totalidad. Permite gestionar el CRUD del archivo de depositos, del archivo de productos y de las existencias en cada depósito. También permite generar un informe de listado de productos con los detalles de cada producto y las existencias en cada depósito, así también como exportar dicho informe en formato .csv.

### Contabilidad

_Desarrollado por: Lucio Luque, Maximiliano Malvicino, Franco Baez_

&nbsp; El módulo puede registrar transacciones de compra y venta de los producotos. Automáticamente cada transacción se registra en el libro diario, en el archivo de cuentas e impacta en el inventario de los depósitos.

- Las transacciones de compra y venta son simplemente una reventa y no es posible agregar valor a un producto o producir un producto a partir de varias existencias. Se propone poder gestionar un warehouse para WIP y Picking de manera que la empresa pueda comprar ciertos productos que sean materia prima y vender ciertos otros que sean productos listos para la venta.

- En versiones posteriores se pretende poder registrar cualquier tipo de transacción, además de compra y venta.

- La contabilidad solo trabaja con 3 cuentas (caja, clientes y proveedores) y en versiones posteriores se pretende poder impactar en cualquier cuenta que un usuario (como por ejemplo el contador de la empresa) necesite generar.

### Recursos humanos

_Desarrollado por: Franco Baez, Lucio Luque_

&nbsp; El módulo permite gestionar el CRUD de los empleados. También permite calcular la antiguedad de los empleados. Se propone para versiones posteriores generar una interfaz de usuario que administre los permisos y brinden accesibilidad o niegen el acceso a los módulos del programa.

### Presupuestos

&nbsp; Se llega a la conclusión de que para generar presupuestos en formato PDF de manera eficiente es necesario implementar herramientas que utilizan otras tecnologías, como por ejemplo Net Core en Visual Studio.

### General

- Se propone que los métodos cin que no lo requieran no reciban por referencia los objetos, sino que modifiquen directamente el atributo. Esto no es posible para los cin de Item y Producto ya que es necesario diferenciar qué atributo se está modificando. Pero el resto se podría simplificar para mayor legibilidad y eficiencia.

- Se propone implementar el menu de listado en el módulo de empleados para unificar la funcionalidad y que tenga la misma interfaz en todo el programa.

- Un empleado en realidad no es un socio de negocio, sino una persona o recurso humano. Para mayor facilidad se heredó desde BusinessPartner pero habría que crear una clase Person para heredar Employee.

- Se podría hacer que la rutina checkAccounts() se genere periódicamente y no solo al inicio, por si el archivo de cuentas es borrado.