#ifndef HITTABLE_H
#define HITTABLE_H

class material;
//hit_record and material require each other, if there is order do u put empty def for both or one and just enforce order
class hit_record {
    public:
        point3 p;
        vec3 normal;
        shared_ptr<material> mat;
        double t;
        bool front_face;

        void set_normal_face(const ray& r, const vec3& outward_normal) {
            //outward normal assumed to have normal length
            //sets hit record normal vec

            front_face = dot(r.direction(), outward_normal) < 0;
            normal = front_face ? outward_normal : -outward_normal;
        }
};

class hittable {
    public:
        virtual ~hittable() = default;

        virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const = 0;
};
#endif
