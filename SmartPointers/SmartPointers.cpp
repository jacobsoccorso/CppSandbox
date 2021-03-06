
#include <iostream>
#include <memory>

class Entity
{
public:

    Entity(int id) : 
        mID(id)
    {
        std::cout << "Constructing Entity " << mID << std::endl;
    }

    virtual ~Entity()
    {
        std::cout << "Destructing Entity " << mID << std::endl;
    }

    void printEntity()
    {
        std::cout << "Entity " << mID << std::endl;
    } 

private:

    int mID;
};

std::shared_ptr<Entity> createEntity(const int& id)
{
    std::shared_ptr<Entity> newEntity = std::make_shared<Entity>(id);
    return newEntity;
}

int main()
{
    // Shared pointers
    std::shared_ptr<Entity> spEntity1;  // Not pointing to anything, yet...
    {
        // Can create shared_ptr from raw pointer
        Entity* tmp = new Entity(2);  // Memory allocated on heap
        std::shared_ptr<Entity> spEntity2(tmp);  // Memory now handled by shared_ptr
        tmp = nullptr;  // For safety because spEntity2 now handles memory

        spEntity1 = spEntity2;  // Add second pointer reference to spEntity2

        // Better to use make_shared() to reduce number of allocations required
        // Allocates new pointer on heap, will be deleted once all pointer references go out of scope
        std::shared_ptr<Entity> spEntity3 = std::make_shared<Entity>(3);

        spEntity1 = spEntity3;  // Add second pointer reference to spEntity3 (decreases pointer reference count to spEntity2)

        std::shared_ptr<Entity> spEntity4 = createEntity(4);

        spEntity1 = spEntity4;
    }

    // Entity pointed to by spEntity1 is not yet destructed because it is still in scope
    spEntity1->printEntity();

    return 0;
}