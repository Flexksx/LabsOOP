package UniversityManagement.Project.classes.serialization;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;

import UniversityManagement.Project.classes.menu.MainMenu;

public class DataSerializer {
    public static void serialize(MainMenu manager) {
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("Manager.ser"))) {
            oos.writeObject(manager);
            System.out.println("Object serialized successfully.");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
