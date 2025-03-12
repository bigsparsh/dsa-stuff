// A university employs different categories of staff, including Teaching Staff
// and Administrative Staff. Some employees may serve both roles simultaneously,
// such as a professor who is also the Head of Department (HOD). Design and
// implement a Java program where: • The Teaching Staff role includes a subject
// specialization. • The Administrative Staff role includes a designation (e.g.,
// HOD, Dean). • An employee can belong to either or both categories.
// Demonstrate the functionality by creating objects for different types of
// staff and displaying their details.

class Employee {
  private String name;
  private int id;
  private double baseSalary;

  public Employee(String name, int id, double baseSalary) {
    this.name = name;
    this.id = id;
    this.baseSalary = baseSalary;
  }

  public String getDetails() {
    return "Employee ID: " + id + ", Name: " + name + ", Base Salary: $" +
        baseSalary;
  }
}

interface TeachingStaff {
  String getTeachingDetails();
}

interface AdministrativeStaff {
  String getAdministrativeDetails();
}

class TeachingEmployee extends Employee implements TeachingStaff {
  private String subjectSpecialization;

  public TeachingEmployee(String name, int id, double baseSalary,
                          String subjectSpecialization) {
    super(name, id, baseSalary);
    this.subjectSpecialization = subjectSpecialization;
  }

  public String getTeachingDetails() {
    return "Subject Specialization: " + subjectSpecialization;
  }

  public String getDetails() {
    return super.getDetails() + "\nRole: Teaching Staff\n" +
        getTeachingDetails();
  }
}

class AdministrativeEmployee extends Employee implements AdministrativeStaff {
  private String designation;

  public AdministrativeEmployee(String name, int id, double baseSalary,
                                String designation) {
    super(name, id, baseSalary);
    this.designation = designation;
  }

  public String getAdministrativeDetails() {
    return "Designation: " + designation;
  }

  public String getDetails() {
    return super.getDetails() + "\nRole: Administrative Staff\n" +
        getAdministrativeDetails();
  }
}

class DualRoleEmployee
    extends Employee implements TeachingStaff, AdministrativeStaff {
  private String subjectSpecialization;
  private String designation;

  public DualRoleEmployee(String name, int id, double baseSalary,
                          String subjectSpecialization, String designation) {
    super(name, id, baseSalary);
    this.subjectSpecialization = subjectSpecialization;
    this.designation = designation;
  }

  public String getTeachingDetails() {
    return "Subject Specialization: " + subjectSpecialization;
  }

  public String getAdministrativeDetails() {
    return "Designation: " + designation;
  }

  public String getDetails() {
    return super.getDetails() + "\nRoles: Teaching & Administrative Staff\n" +
        getTeachingDetails() + "\n" + getAdministrativeDetails();
  }
}

public class PG5 {
  public static void main(String[] args) {
    TeachingEmployee professor =
        new TeachingEmployee("Dr. Jane Smith", 1001, 80000, "Computer Science");

    AdministrativeEmployee admin =
        new AdministrativeEmployee("John Williams", 2001, 65000, "Registrar");

    DualRoleEmployee dualRole = new DualRoleEmployee(
        "Dr. Robert Johnson", 3001, 95000, "Physics", "Head of Department");

    System.out.println("===== University Staff Details =====");
    System.out.println("\n1. Teaching Staff:");
    System.out.println(professor.getDetails());

    System.out.println("\n2. Administrative Staff:");
    System.out.println(admin.getDetails());

    System.out.println("\n3. Dual Role Staff:");
    System.out.println(dualRole.getDetails());
  }
}
