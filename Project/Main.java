package Project;

import java.util.ArrayList;
import Project.classes.mainclasses.Faculty;
import Project.classes.menu.*;
import Project.classes.serialization.DataDeserializer;

public class Main {
    static ArrayList<Faculty> faculties = new ArrayList<>();

    public static void main(String[] args) {
        System.out.println("Hello, this is a University Manager project made by Cretu Cristian as a OOP project");
        MainMenu menu = DataDeserializer.deserialize();
        menu.setFaculties(faculties);
        menu.mainLoop();
    }
}