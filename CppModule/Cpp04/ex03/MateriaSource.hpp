/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:18:33 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/02 22:33:20 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
 private:
  AMateria* materias[4];

 public:
  MateriaSource();
  MateriaSource(const MateriaSource& other);
  virtual ~MateriaSource();

  MateriaSource& operator=(const MateriaSource& other);

  virtual void learnMateria(AMateria* materia);
  virtual AMateria* createMateria(std::string const& type);
};

#endif