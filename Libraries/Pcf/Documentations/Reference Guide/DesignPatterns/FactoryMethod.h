/**
 * @page FactoryMethodPage Factory Method
 *
 * Creates an instance of several derived classes
 *
 * @section DefinitionSection Definition
 * Define an interface for creating an object, but let subclasses decide which class to instantiate. Factory Method lets a class defer instantiation to subclasses.
 *
 * @section UmlClassDiagramSection UML class diagram
 * @image html factory.gif
 *
 * @section SampleCodeSection Sample code
 * This structural code demonstrates the Factory method offering great flexibility in creating different objects. The Abstract class may provide a default object, but each subclass can instantiate an extended version of the object.
 * @include FactoryMethod.cpp
 */
