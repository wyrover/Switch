/**
 * @page TemplateMethodPage Template Method
 *
 * Defer the exact steps of an algorithm to a subclass
 *
 * @section DefinitionSection Definition
 * Define the skeleton of an algorithm in an operation, deferring some steps to subclasses. Template Method lets subclasses redefine certain steps of an algorithm without changing the algorithm's structure.
 *
 * @section UmlClassDiagramSection UML class diagram
 * @image html template.gif
 *
 * @section SampleCodeSection Sample code
 * This structural code demonstrates the Template method which provides a skeleton calling sequence of methods. One or more steps can be deferred to subclasses which implement these steps without changing the overall calling sequence.
 * @include TemplateMethod.cpp
 */
