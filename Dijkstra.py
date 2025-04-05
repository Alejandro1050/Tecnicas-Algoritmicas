# Algoritmo Djikstra
"""
 Este algoritmo se utiliza para encontrar el camino más corto entre dos nodos en un grafo ponderado.
 En este caso, se utiliza para encontrar el camino más corto entre dos ciudades en un mapa.
 Se utiliza una lista de adyacencia para representar el grafo y un diccionario para almacenar los costos de cada nodo.
 El algoritmo funciona de la siguiente manera:

 Fue creado y publicado por el Dr. Edsger W. Dijkstra, un científico Neerlandés brillante en ciencias de la 
 computación e ingeniería de software.

 En 1959, publicó un artículo de tres páginas titulado: "A note on two problems in connexion with graphs", 
 lo cual se traduce a español como "Una nota sobre dos problemas relacionados con grafos." En este artículo 
 explicó su nuevo algoritmo.
"""
import heapq

def dijkstra(graph, start):
    """
    Implementación del algoritmo de Dijkstra para encontrar el camino más corto
    desde un nodo inicial a todos los demás nodos en un grafo ponderado.
    
    Parámetros:
    graph: Un diccionario de diccionarios donde graph[u][v] es el peso de la arista (u,v)
    start: El nodo inicial
    
    Retorna:
    distances: Un diccionario con las distancias más cortas desde el nodo inicial a cada nodo
    predecessors: Un diccionario con el predecesor de cada nodo en el camino más corto
    """
    # Inicializar distancias como infinito para todos los nodos excepto el inicial
    distances = {node: float('infinity') for node in graph}
    distances[start] = 0
    
    # Diccionario para guardar el predecesor de cada nodo
    predecessors = {node: None for node in graph}
    
    # Cola de prioridad para seleccionar el nodo con la distancia mínima
    priority_queue = [(0, start)]
    
    while priority_queue:
        # Obtener el nodo con la distancia mínima
        current_distance, current_node = heapq.heappop(priority_queue)
        
        # Si la distancia actual es mayor que la ya conocida, ignorar
        if current_distance > distances[current_node]:
            continue
        
        # Explorar todos los vecinos del nodo actual
        for neighbor, weight in graph[current_node].items():
            distance = current_distance + weight
            
            # Si encontramos un camino más corto al vecino
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                predecessors[neighbor] = current_node
                heapq.heappush(priority_queue, (distance, neighbor))
    
    return distances, predecessors

def get_shortest_path(predecessors, target):
    """
    Reconstruye el camino más corto a partir del diccionario de predecesores
    
    Parámetros:
    predecessors: Diccionario de predecesores obtenido de dijkstra()
    target: Nodo destino
    
    Retorna:
    Una lista con el camino desde el nodo inicial hasta el nodo destino
    """
    path = []
    current = target
    
    # Reconstruir el camino yendo hacia atrás
    while current is not None:
        path.append(current)
        current = predecessors[current]
    
    # Invertir el camino para obtenerlo desde el inicio hasta el destino
    return path[::-1]

# Ejemplo de uso
if __name__ == "__main__":
    # Definir un grafo como diccionario de diccionarios
    # donde graph[u][v] es el peso de la arista desde u hasta v
    graph = {
        'A': {'B': 5, 'C': 1},
        'B': {'A': 5, 'C': 2, 'D': 1},
        'C': {'A': 1, 'B': 2, 'D': 4, 'E': 8},
        'D': {'B': 1, 'C': 4, 'E': 3, 'F': 6},
        'E': {'C': 8, 'D': 3},
        'F': {'D': 6}
    }
    
    # Ejecutar el algoritmo de Dijkstra desde el nodo 'A'
    distances, predecessors = dijkstra(graph, 'A')
    
    # Mostrar las distancias más cortas desde 'A' a todos los nodos
    print("Distancias más cortas desde A:")
    for node, distance in distances.items():
        print(f"A -> {node}: {distance}")
    
    # Mostrar el camino más corto desde 'A' hasta 'F'
    path = get_shortest_path(predecessors, 'F')
    print("\nCamino más corto de A a F:", " -> ".join(path))
