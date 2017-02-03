/**
 * @page ChainOfResponsabilityPage Chain of Responsability
 *
 * A way of passing a request between a chain of objects
 *
 * @section DefinitionSection Definition
 * Avoid coupling the sender of a request to its receiver by giving more than one object a chance to handle the request. Chain the receiving objects and pass the request along the chain until an object handles it. 
 *
 * @section UmlClassDiagramSection UML class diagram
 * @image html chain.gif
 *
 * @section SampleCodeSection Sample code
 * This structural code demonstrates the Chain of Responsibility pattern in which several linked objects (the Chain) are offered the opportunity to respond to a request or hand it off to the object next in line.
 * @include ChainOfResponsability.cpp
 */
